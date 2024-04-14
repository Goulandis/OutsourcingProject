import sys
from PyQt5.QtGui import QPixmap
from PyQt5.QtWidgets import *
from PyQt5 import QtCore, QtGui, QtWidgets

class ImageLabel(QWidget):
    def __init__(self,parent=None):
        super().__init__(parent)
        self.resize(600,600)
        self.setWindowTitle("label image")
        pix = QPixmap("E:/Git/ZJChinaMobile/区域标准.jpg")
        label = QLabel(self)
        label.setPixmap(pix)
        label.setScaledContents(True)
        layout = QVBoxLayout()
        layout.addWidget(label)
        self.setLayout(layout)

class FileHandleWidget(object):
  def setupUi(self, Form):
    Form.setObjectName("Form")
    Form.resize(443, 120)
    self.widget = QtWidgets.QWidget(Form)
    self.widget.setGeometry(QtCore.QRect(50, 40, 301, 25))
    self.widget.setObjectName("widget")
    self.horizontalLayout = QtWidgets.QHBoxLayout(self.widget)
    self.horizontalLayout.setContentsMargins(0, 0, 0, 0)
    self.horizontalLayout.setObjectName("horizontalLayout")
    self.openFileButton = QtWidgets.QPushButton(self.widget)
    self.openFileButton.setObjectName("openFileButton")
    self.horizontalLayout.addWidget(self.openFileButton)
    self.filePathlineEdit = QtWidgets.QLineEdit(self.widget)
    self.filePathlineEdit.setObjectName("filePathlineEdit")
    self.horizontalLayout.addWidget(self.filePathlineEdit)
    self.retranslateUi(Form)
    QtCore.QMetaObject.connectSlotsByName(Form)
  def retranslateUi(self, Form):
    _translate = QtCore.QCoreApplication.translate
    Form.setWindowTitle(_translate("Form", "QFileDialog打开文件例子"))
    self.openFileButton.setText(_translate("Form", "打开文件"))
    
class MainForm(QMainWindow, FileHandleWidget):
  def __init__(self, parent=None):
    super(MainForm, self).__init__(parent)
    self.setupUi(self)
    self.openFileButton.clicked.connect(self.openFile)
  def openFile(self):
    get_filenames_path, ok = QFileDialog.getOpenFileNames(self,
                  "选取多个文件",
                  "C:/",
                  "All Files (*);;Text Files (*.txt)")
    if ok:
      self.filePathlineEdit.setText(str(' '.join(get_filenames_path)))

class Window(QMainWindow):
    def __init__(self):
        super().__init__()
        self.setWindowTitle('My first window - www.luochang.ink')
        self.Width = 1000
        self.height = int(0.618 * self.Width)
        self.resize(self.Width, self.height)

        #self.

        #self.initUI()
    def initUI(self):
        self.btn1 = QPushButton('1', self)
        self.btn1.resize(300,90)
        self.btn2 = QPushButton('2',self)
        self.btn2.resize(300,90)
        btn_layout = QVBoxLayout()
        btn_layout.addWidget(self.btn1)
        btn_layout.addWidget(self.btn2)
        mainWidget = QWidget()
        mainWidget.setLayout(btn_layout)
        self.setCentralWidget(mainWidget)

if __name__ == "__main__":
    app = QApplication(sys.argv)
    mainWidget = MainForm()
    mainWidget.show()
    sys.exit(app.exec())