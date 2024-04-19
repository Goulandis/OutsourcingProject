import json
import os
import subprocess
try:
    import ppt2gif
    print("Module:ppt2gif installed")
except ImportError:
    print("Module:ppt2gif uninstalled so try to install")
    subprocess.call(['python','-m','pip','install','ppt2gif==1.0.2'])
try:
    import shutil
    print("Module:shutil installed")
except ImportError:
    print("Module:shutil uninstalled so try to install")
    subprocess.call(['python','-m','pip','install','shutil'])

def GetPPTsFromDir(RootDir,PPTs):
    Files = os.listdir(RootDir)
    for File in Files:
        FilePath = os.path.join(RootDir,File)
        if os.path.isfile(FilePath) and FilePath.endswith(".pptx"):
            PPTs.append(FilePath)
        elif os.path.isdir(FilePath):
            GetPPTsFromDir(FilePath,PPTs)

def DeleteRedundancyDir(RootDir):
    Files = os.listdir(RootDir)
    Dirs = []
    for File in Files:
        FilePath = os.path.join(RootDir,File)
        if os.path.isdir(FilePath):
            Dirs.append(FilePath)
    for Dir in Dirs:
        Files = os.listdir(Dir)
        for File in Files:
            FilePath = os.path.join(Dir,File)
            if os.path.isdir(FilePath):
                shutil.rmtree(FilePath)

def PPT2PNG(PPTs):
    PPTObj = ppt2gif.PPT(PPTs)
    PPTObj.convert2png()

JsonPath = os.path.split(os.path.realpath(__file__))[0] + "\Config\Config.json"
print(JsonPath)
with open(JsonPath,'r') as File:
    Config = json.load(File)
    print('Loaded config file : '+JsonPath)

PPTDir = os.path.split(os.path.realpath(__file__))[0] + "\DiyContents"
PPTDirConfig = Config['Display']['PPTDir']
if PPTDirConfig != "":
    PPTDir = PPTDirConfig

PPTs = []
DeleteRedundancyDir(PPTDir)
GetPPTsFromDir(PPTDir,PPTs)
PPT2PNG(PPTs)

