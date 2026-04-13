require('dotenv').config();
const amqp = require('amqplib');
const readline = require('readline');

const RABBITMQ_URL = process.env.RABBITMQ_URL;
const EXCHANGE_NAME = process.env.EXCHANGE_NAME || 'amq.topic';

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

const ask = (q) => new Promise((resolve) => rl.question(q, resolve));

async function main() {
  const queueName = (await ask('Masukkan queue name: ')).trim();
  const routingKey = (await ask('Masukkan routing key: ')).trim();

  if (!queueName || !routingKey) {
    console.error('Queue name dan routing key tidak boleh kosong.');
    rl.close();
    process.exit(1);
  }

  try {
    const connection = await amqp.connect(RABBITMQ_URL);
    const channel = await connection.createChannel();

    await channel.assertExchange(EXCHANGE_NAME, 'topic', { durable: true });
    await channel.assertQueue(queueName, { durable: true });
    await channel.bindQueue(queueName, EXCHANGE_NAME, routingKey);

    console.log(`Connected to exchange: ${EXCHANGE_NAME}`);
    console.log(`Queue: ${queueName}`);
    console.log(`Binding key: ${routingKey}`);
    console.log('Waiting for messages...');

    channel.consume(queueName, (msg) => {
      if (!msg) return;
      console.log('--- Message received ---');
      console.log('Routing key:', msg.fields.routingKey);
      console.log('Content:', msg.content.toString());
    }, { noAck: true });

    process.on('SIGINT', async () => {
      await channel.close().catch(() => {});
      await connection.close().catch(() => {});
      rl.close();
      process.exit(0);
    });
  } catch (err) {
    console.error('Error:', err.message);
    rl.close();
    process.exit(1);
  }
}

main();