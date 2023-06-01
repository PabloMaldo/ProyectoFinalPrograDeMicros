from PySide2.QtCore import QTimer
from PySide2.QtWidgets import QMainWindow, QApplication
from ui_mainwindow_arm import Ui_MainWindow
import serial

# ---------------------------- CONECTANDO CON ADAFRUIT ---------------------------------
# import system libraries
import time, random


# import Adafruit IO REST client
from Adafruit_IO import Client, Feed, RequestError

# Set to your Adafruit IO key.
# Remember, your key is a secret,
# so make sure not to publish it when you publish this code!
ADAFRUIT_IO_KEY = 'aio_SFjs81gR4a7GNgus98JZOqllYa9y'

# Set to your Adafruit IO username.
# (go to https://accounts.adafruit.com to find your username)
ADAFRUIT_IO_USERNAME = 'pgmaldonado'

# Create an instance of the REST client.
aio = Client(ADAFRUIT_IO_USERNAME, ADAFRUIT_IO_KEY)

# SERVO 1
try: # if we have a 'analog' feed
    feed_00 = aio.feeds('servo1')
except RequestError: # create an `analog` feed
    feed = Feed(name='servo1')
    feed_00 = aio.create_feed(feed)

# SERVO 2
try: # if we have a 'analog' feed
    feed_01 = aio.feeds('servo2')
except RequestError: # create an `analog` feed
    feed = Feed(name='servo2')
    feed_01 = aio.create_feed(feed)
    
# SERVO 3
try: # if we have a 'analog' feed
    feed_02 = aio.feeds('servo3')
except RequestError: # create an `analog` feed
    feed = Feed(name='servo3')
    feed_02 = aio.create_feed(feed)
    
# SERVO 4
try: # if we have a 'analog' feed
    feed_03 = aio.feeds('servo4')
except RequestError: # create an `analog` feed
    feed = Feed(name='servo4')
    feed_03 = aio.create_feed(feed) 
   

class MainWindow(QMainWindow, Ui_MainWindow):
    def __init__(self):
        super().__init__()
        self.setupUi(self)

        self.serial_port = None

        self.pushButton.clicked.connect(self.connect_port)
        self.pushButton_2.clicked.connect(self.close_port)
        self.pushButton_3.clicked.connect(self.update_data)
        
        self.horizontalSlider.setRange(0, 180)
        self.horizontalSlider_2.setRange(0, 180)
        self.horizontalSlider_3.setRange(0, 180)
        self.horizontalSlider_4.setRange(0, 180)
        
        self.horizontalSlider.valueChanged.connect(lambda position: self.send_slider_position(position, 1))
        self.horizontalSlider_2.valueChanged.connect(lambda position: self.send_slider_position(position, 2))
        self.horizontalSlider_3.valueChanged.connect(lambda position: self.send_slider_position(position, 3))
        self.horizontalSlider_4.valueChanged.connect(lambda position: self.send_slider_position(position, 4))

        self.timer = QTimer(self)
        self.timer.timeout.connect(self.receive_data)
        self.timer.start(100)

    def connect_port(self):
        port_name = self.comboBox.currentText()
        try:
            self.serial_port = serial.Serial(port_name, 9600)
        except serial.SerialException as e:
            self.statusbar.showMessage(str(e))

    def send_slider_position(self, position, num):
        angle = position  # Aquí puedes aplicar cualquier transformación necesaria
        data = str(angle).encode(encoding="ascii", errors="replace")  # Convertir el ángulo a bytes
        length = len(data)
        if length == 1:
            trans1 = int(data)
            paso = "00"+str(trans1)+str(num)
            new_val = paso.encode(encoding="ascii", errors="replace")
        elif length == 2:
            trans1 = int(data)
            paso = "0"+str(trans1)+str(num)
            new_val = paso.encode(encoding="ascii", errors="replace")
        else:
            new_val = data
        self.serial_port.write(new_val)

    def update_data(self):
        prev_read1 = 0 
        prev_read2 = 0  
        prev_read3 = 0  
        prev_read4 = 0
        read1 = aio.receive(feed_00.key)
        if (read1.value != prev_read1):
            var1 = int(read1.value)
            self.horizontalSlider.setValue(var1)
        prev_read1 = read1.value
            
        read2 = aio.receive(feed_01.key)
        if (read2.value != prev_read2):
            var2 = int(read2.value)
            self.horizontalSlider_2.setValue(var2)
        prev_read2 = read2.value
            
        read3 = aio.receive(feed_02.key)
        if (read3.value != prev_read3):
            var3 = int(read3.value)
            self.horizontalSlider_3.setValue(var3)
        prev_read3 = read3.value
            
        read4 = aio.receive(feed_03.key)
        if (read4.value != prev_read4):
            var4 = int(read4.value)
            self.horizontalSlider_4.setValue(var4)
        prev_read4 = read4.value
        
    def receive_data(self):
        if self.serial_port is not None:
            data = self.serial_port.read_all().decode(encoding="ascii", errors="replace")
            if data:
                self.textBrowser.append(data)

    def close_port(self):
        if self.serial_port is not None:
            self.serial_port.close()
            self.serial_port = None

if __name__ == '__main__':
    app = QApplication()
    window = MainWindow()
    window.show()
    app.exec_()