# spiogn.py
import sys
from PyQt5.QtWidgets import QApplication, QWidget, QVBoxLayout, QListWidget, QPushButton, QLabel

class AssetStore(QWidget):
    def __init__(self, assets):
        super().__init__()
        self.setWindowTitle("Asset Store")
        self.setGeometry(150, 150, 400, 600)

        layout = QVBoxLayout()
        self.setLayout(layout)

        # Список ассетів
        self.asset_list = QListWidget()
        for asset in assets:
            self.asset_list.addItem(asset)
        layout.addWidget(QLabel("Available Assets:"))
        layout.addWidget(self.asset_list)

        # Кнопка додати ассет у сцену
        self.add_button = QPushButton("Add Asset to Scene")
        self.add_button.clicked.connect(self.add_asset)
        layout.addWidget(self.add_button)

    def add_asset(self):
        selected = self.asset_list.currentItem()
        if selected:
            print(f"Added {selected.text()} to scene")
            # Тут підключається логіка для вставки 3D моделі у сцену

# Тестові ассети
assets = ["Tree_Model", "Rock_Model", "House_Model", "Character_Model"]

if __name__ == "__main__":
    app = QApplication(sys.argv)
    window = AssetStore(assets)
    window.show()
    sys.exit(app.exec_())
