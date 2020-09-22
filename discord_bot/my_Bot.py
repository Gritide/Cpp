import discord
from discord.ext.commands import Bot
from discord.ext import commands
import asyncio
import time

Client = discord.Client()
client = commands.Bot(command_prefix = ",")

@client.event
async def on_ready() :
    print("Bot is ready!")


@client.event
async def on_message(message) :
    if message.content == ",donut": 
        await client.send_message(message.channel, ":doughnut:")
    elif message.content==",domuz":
        await client.send_message(message.channel, ":bacon:")
    elif message.content==",shine":
        await client.send_message(message.channel, ":skull_crossbones:")
    elif message.content==",aferin":
        await client.send_message(message.channel, ":clap:")



client.run("cRP67xVyXu42yn1KTwgNWetIggs649k")
