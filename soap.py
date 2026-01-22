# soap.py
import sys
from PyQt5.QtWidgets import QApplication, QMainWindow, QToolBar, QAction
from PyQt5.QtGui import QIcon

class TopPanel(QMainWindow):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("GS+6 Editor")
        self.setGeometry(100, 100, 1200, 800)

        # Створюємо панель інструментів
        self.toolbar = QToolBar("Top Toolbar")
        self.addToolBar(self.toolbar)

        # Додаємо кнопки
        self.add_toolbar_button("Select", "icons/select.png")
        self.add_toolbar_button("Move", "icons/move.png")
        self.add_toolbar_button("Rotate", "icons/rotate.png")
        self.add_toolbar_button("Scale", "icons/scale.png")
        self.add_toolbar_button("Run Game", "icons/run.png")

    def add_toolbar_button(self, name, icon_path):
        action = QAction(QIcon(icon_path), name, self)
        self.toolbar.addAction(action)

# Для тесту
if __name__ == "__main__":
    app = QApplication(sys.argv)
    window = TopPanel()
    window.show()
    sys.exit(app.exec_())
