import tkinter as tk
from tkinter import ttk

# =================================================
# Editor Core
# =================================================

class EngineEditorUI:

    def __init__(self, root):
        self.root = root
        self.root.title("RTXC Engine Editor")
        self.root.geometry("1400x850")
        self.root.configure(bg="#1e1e1e")

        self._style()
        self._menu()
        self._layout()
        self._tools()

    # =================================================
    # Style (Dark Editor Style)
    # =================================================

    def _style(self):
        style = ttk.Style()
        style.theme_use("default")

        style.configure("TFrame", background="#1e1e1e")
        style.configure("TLabel", background="#1e1e1e", foreground="#d0d0d0")
        style.configure("TButton", background="#2a2a2a", foreground="#ffffff")
        style.configure("Treeview",
                        background="#252526",
                        fieldbackground="#252526",
                        foreground="#dcdcdc",
                        borderwidth=0)

    # =================================================
    # Top Menu Bar
    # =================================================

    def _menu(self):
        menubar = tk.Menu(self.root, bg="#1e1e1e", fg="white")

        file_menu = tk.Menu(menubar, tearoff=0)
        file_menu.add_command(label="New Scene")
        file_menu.add_command(label="Open Scene")
        file_menu.add_command(label="Save Scene")

        edit_menu = tk.Menu(menubar, tearoff=0)
        edit_menu.add_command(label="Undo")
        edit_menu.add_command(label="Redo")

        view_menu = tk.Menu(menubar, tearoff=0)
        view_menu.add_command(label="Viewport")
        view_menu.add_command(label="Inspector")
        view_menu.add_command(label="Outliner")

        tools_menu = tk.Menu(menubar, tearoff=0)
        tools_menu.add_command(label="Translate Tool")
        tools_menu.add_command(label="Rotate Tool")
        tools_menu.add_command(label="Scale Tool")

        menubar.add_cascade(label="File", menu=file_menu)
        menubar.add_cascade(label="Edit", menu=edit_menu)
        menubar.add_cascade(label="View", menu=view_menu)
        menubar.add_cascade(label="Tools", menu=tools_menu)

        self.root.config(menu=menubar)

    # =================================================
    # Main Layout
    # =================================================

    def _layout(self):
        self.main = ttk.Frame(self.root)
        self.main.pack(fill=tk.BOTH, expand=True)

        # Left panel (Outliner + Assets)
        self.left = ttk.Frame(self.main, width=260)
        self.left.pack(side=tk.LEFT, fill=tk.Y)

        # Center viewport
        self.center = ttk.Frame(self.main)
        self.center.pack(side=tk.LEFT, fill=tk.BOTH, expand=True)

        # Right inspector
        self.right = ttk.Frame(self.main, width=320)
        self.right.pack(side=tk.RIGHT, fill=tk.Y)

        self._outliner()
        self._assets()
        self._viewport()
        self._inspector()

    # =================================================
    # Outliner (Scene Hierarchy)
    # =================================================

    def _outliner(self):
        label = ttk.Label(self.left, text="OUTLINER")
        label.pack(anchor="w", padx=6, pady=4)

        self.outliner = ttk.Treeview(self.left)
        self.outliner.pack(fill=tk.BOTH, expand=True, padx=4)

        root = self.outliner.insert("", "end", text="Scene")
        self.outliner.insert(root, "end", text="Camera")
        self.outliner.insert(root, "end", text="DirectionalLight")
        self.outliner.insert(root, "end", text="Player")
        self.outliner.insert(root, "end", text="Environment")

    # =================================================
    # Assets Browser
    # =================================================

    def _assets(self):
        label = ttk.Label(self.left, text="ASSETS")
        label.pack(anchor="w", padx=6, pady=4)

        assets = ttk.Treeview(self.left, height=6)
        assets.pack(fill=tk.X, padx=4)

        assets.insert("", "end", text="Meshes")
        assets.insert("", "end", text="Materials")
        assets.insert("", "end", text="Textures")
        assets.insert("", "end", text="Scripts")

    # =================================================
    # Viewport (Editor View)
    # =================================================

    def _viewport(self):
        viewport_label = ttk.Label(self.center, text="VIEWPORT")
        viewport_label.pack(anchor="w", padx=6, pady=4)

        self.viewport = tk.Canvas(
            self.center,
            bg="#121212",
            highlightthickness=0
        )
        self.viewport.pack(fill=tk.BOTH, expand=True, padx=6, pady=6)

        self.viewport.create_text(
            400, 300,
            text="3D VIEWPORT\n(Render disabled)",
            fill="#555555",
            font=("Arial", 14)
        )

    # =================================================
    # Inspector (Properties Panel)
    # =================================================

    def _inspector(self):
        label = ttk.Label(self.right, text="INSPECTOR")
        label.pack(anchor="w", padx=6, pady=4)

        self._prop("Transform")
        self._field("Position", "0 0 0")
        self._field("Rotation", "0 0 0")
        self._field("Scale", "1 1 1")

        self._prop("Rendering")
        self._field("Mesh", "None")
        self._field("Material", "Default")

        self._prop("Logic")
        self._field("Script", "None")

    def _prop(self, name):
        ttk.Label(self.right, text=name.upper()).pack(anchor="w", padx=6, pady=(10,2))

    def _field(self, name, value):
        frame = ttk.Frame(self.right)
        frame.pack(fill=tk.X, padx=6, pady=2)

        ttk.Label(frame, text=name, width=10).pack(side=tk.LEFT)
        entry = ttk.Entry(frame)
        entry.insert(0, value)
        entry.pack(side=tk.RIGHT, fill=tk.X, expand=True)

    # =================================================
    # Tools (Editor Toolbar Logic)
    # =================================================

    def _tools(self):
        self.active_tool = "Translate"


# =================================================
# Run Editor
# =================================================

if __name__ == "__main__":
    root = tk.Tk()
    app = EngineEditorUI(root)
    root.mainloop()