import json
import os

JsonPath = os.path.split(os.path.realpath(__file__))[0] + "\Config.json"
with open(JsonPath,'r') as File:
    Config = json.load(File)
    print('Loaded config file : '+JsonPath)


PythonServer = Config['PythonServer']
TimeDelay = PythonServer['TimeDelay']
StartFileDelay = TimeDelay['StartFileDelay']
OpenFilweMenuDelay = TimeDelay['OpenFilweMenuDelay']
OpenOutputImgTagDelay = TimeDelay['OpenOutputImgTagDelay']
OutputImgDelay = TimeDelay['OutputImgDelay']
CloseOutputImgTagDelay = TimeDelay['CloseOutputImgTagDelay']
OpenNextPPTDelay = TimeDelay['OpenNextPPTDelay']

PPTDir = PythonServer['PPTDir']

IP = PythonServer['IP']
Port = PythonServer['Port']
UpdRecvSize = PythonServer['UpdRecvSize']