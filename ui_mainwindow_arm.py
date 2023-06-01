# -*- coding: utf-8 -*-

################################################################################
## Form generated from reading UI file 'designerDIQMPd.ui'
##
## Created by: Qt User Interface Compiler version 5.15.2
##
## WARNING! All changes made in this file will be lost when recompiling UI file!
################################################################################

from PySide2.QtCore import *
from PySide2.QtGui import *
from PySide2.QtWidgets import *


class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        if not MainWindow.objectName():
            MainWindow.setObjectName(u"MainWindow")
        MainWindow.resize(515, 581)
        self.centralwidget = QWidget(MainWindow)
        self.centralwidget.setObjectName(u"centralwidget")
        self.horizontalSlider = QSlider(self.centralwidget)
        self.horizontalSlider.setObjectName(u"horizontalSlider")
        self.horizontalSlider.setGeometry(QRect(160, 100, 311, 31))
        self.horizontalSlider.setOrientation(Qt.Horizontal)
        self.horizontalSlider_2 = QSlider(self.centralwidget)
        self.horizontalSlider_2.setObjectName(u"horizontalSlider_2")
        self.horizontalSlider_2.setGeometry(QRect(160, 170, 311, 31))
        self.horizontalSlider_2.setOrientation(Qt.Horizontal)
        self.horizontalSlider_3 = QSlider(self.centralwidget)
        self.horizontalSlider_3.setObjectName(u"horizontalSlider_3")
        self.horizontalSlider_3.setGeometry(QRect(160, 240, 311, 31))
        self.horizontalSlider_3.setOrientation(Qt.Horizontal)
        self.horizontalSlider_4 = QSlider(self.centralwidget)
        self.horizontalSlider_4.setObjectName(u"horizontalSlider_4")
        self.horizontalSlider_4.setGeometry(QRect(160, 310, 311, 31))
        self.horizontalSlider_4.setOrientation(Qt.Horizontal)
        self.pushButton = QPushButton(self.centralwidget)
        self.pushButton.setObjectName(u"pushButton")
        self.pushButton.setGeometry(QRect(300, 40, 81, 31))
        self.comboBox = QComboBox(self.centralwidget)
        self.comboBox.addItem("")
        self.comboBox.addItem("")
        self.comboBox.addItem("")
        self.comboBox.addItem("")
        self.comboBox.addItem("")
        self.comboBox.addItem("")
        self.comboBox.addItem("")
        self.comboBox.addItem("")
        self.comboBox.addItem("")
        self.comboBox.addItem("")
        self.comboBox.setObjectName(u"comboBox")
        self.comboBox.setGeometry(QRect(30, 40, 91, 31))
        self.pushButton_2 = QPushButton(self.centralwidget)
        self.pushButton_2.setObjectName(u"pushButton_2")
        self.pushButton_2.setGeometry(QRect(400, 40, 81, 31))
        self.textBrowser = QTextBrowser(self.centralwidget)
        self.textBrowser.setObjectName(u"textBrowser")
        self.textBrowser.setGeometry(QRect(30, 370, 451, 131))
        self.pushButton_3 = QPushButton(self.centralwidget)
        self.pushButton_3.setObjectName(u"pushButton_3")
        self.pushButton_3.setGeometry(QRect(190, 40, 81, 31))
        self.label = QLabel(self.centralwidget)
        self.label.setObjectName(u"label")
        self.label.setGeometry(QRect(60, 110, 55, 16))
        self.label_2 = QLabel(self.centralwidget)
        self.label_2.setObjectName(u"label_2")
        self.label_2.setGeometry(QRect(60, 180, 55, 16))
        self.label_3 = QLabel(self.centralwidget)
        self.label_3.setObjectName(u"label_3")
        self.label_3.setGeometry(QRect(60, 250, 55, 16))
        self.label_4 = QLabel(self.centralwidget)
        self.label_4.setObjectName(u"label_4")
        self.label_4.setGeometry(QRect(60, 320, 55, 16))
        MainWindow.setCentralWidget(self.centralwidget)
        self.menubar = QMenuBar(MainWindow)
        self.menubar.setObjectName(u"menubar")
        self.menubar.setGeometry(QRect(0, 0, 515, 26))
        MainWindow.setMenuBar(self.menubar)
        self.statusbar = QStatusBar(MainWindow)
        self.statusbar.setObjectName(u"statusbar")
        MainWindow.setStatusBar(self.statusbar)

        self.retranslateUi(MainWindow)

        QMetaObject.connectSlotsByName(MainWindow)
    # setupUi

    def retranslateUi(self, MainWindow):
        MainWindow.setWindowTitle(QCoreApplication.translate("MainWindow", u"MainWindow", None))
        self.pushButton.setText(QCoreApplication.translate("MainWindow", u"CONECTAR", None))
        self.comboBox.setItemText(0, QCoreApplication.translate("MainWindow", u"COM0", None))
        self.comboBox.setItemText(1, QCoreApplication.translate("MainWindow", u"COM1", None))
        self.comboBox.setItemText(2, QCoreApplication.translate("MainWindow", u"COM2", None))
        self.comboBox.setItemText(3, QCoreApplication.translate("MainWindow", u"COM3", None))
        self.comboBox.setItemText(4, QCoreApplication.translate("MainWindow", u"COM4", None))
        self.comboBox.setItemText(5, QCoreApplication.translate("MainWindow", u"COM5", None))
        self.comboBox.setItemText(6, QCoreApplication.translate("MainWindow", u"COM6", None))
        self.comboBox.setItemText(7, QCoreApplication.translate("MainWindow", u"COM7", None))
        self.comboBox.setItemText(8, QCoreApplication.translate("MainWindow", u"COM8", None))
        self.comboBox.setItemText(9, QCoreApplication.translate("MainWindow", u"COM9", None))

        self.pushButton_2.setText(QCoreApplication.translate("MainWindow", u"CERRAR", None))
        self.pushButton_3.setText(QCoreApplication.translate("MainWindow", u"UPDATE", None))
        self.label.setText(QCoreApplication.translate("MainWindow", u"Motor 1", None))
        self.label_2.setText(QCoreApplication.translate("MainWindow", u"Motor 2", None))
        self.label_3.setText(QCoreApplication.translate("MainWindow", u"Motor 3", None))
        self.label_4.setText(QCoreApplication.translate("MainWindow", u"Motor 4", None))
    # retranslateUi

