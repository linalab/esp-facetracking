import argparse
import random
import time
from pythonosc import udp_client


if __name__ == "__main__":
  parser = argparse.ArgumentParser()
  parser.add_argument("--ip", default="192.168.8.210", # ip del ordenador al que envío
      help="The ip of the OSC server")
  parser.add_argument("--port", type=int, default=12000,
      help="The port the OSC server is listening on")
  args = parser.parse_args()

  client = udp_client.SimpleUDPClient(args.ip, args.port)

while True:
    variable = random.random()
    client.send_message("/touch1", variable)
    client.send_message("/filter", random.random())
    client.send_message("/miau", random.randint(0,3))
    client.send_message("/miau", random.randint(0,3))
    var = random.randint(1,5)
    time.sleep(var)
