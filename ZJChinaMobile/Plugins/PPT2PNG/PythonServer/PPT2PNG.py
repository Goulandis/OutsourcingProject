import pyautogui
import time
import os
import shutil
import Config


def PPTOutputPNG(FilePath):
    os.startfile(FilePath)
    time.sleep(Config.StartFileDelay)
    pyautogui.hotkey('alt','f')
    time.sleep(Config.OpenFilweMenuDelay)
    pyautogui.hotkey('g')
    time.sleep(Config.OpenOutputImgTagDelay)
    pyautogui.press('enter')
    time.sleep(Config.OutputImgDelay)
    pyautogui.hotkey('alt','f4')
    time.sleep(Config.CloseOutputImgTagDelay)
    pyautogui.hotkey('alt','f4')

def GetPPTFromDir(RootDir,PPTs):
    Files = os.listdir(RootDir)
    for File in Files:
        FilePath = os.path.join(RootDir,File)
        if os.path.isfile(FilePath) and FilePath.endswith(".pptx"):
            PPTs.append(FilePath)
        elif os.path.isdir(FilePath):
            GetPPTFromDir(FilePath,PPTs)

def PPTToPNGBatch(PPTs):
    for File in PPTs:
        PPTOutputPNG(File)
        time.sleep(Config.OpenNextPPTDelay)
    pyautogui.hotkey('alt','f4')

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

def PPT2NPG():
    PPTs = []            
    DeleteRedundancyDir(Config.PPTDir)
    GetPPTFromDir(Config.PPTDir,PPTs)
    PPTToPNGBatch(PPTs)

PPT2NPG()