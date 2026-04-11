import matplotlib.pyplot as plt
import matplotlib
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
import tkinter as tk
import numpy as np
import sys

dirs = {
    "L": (-1,0),
    "R": (1,0),
    "U": (0,1),
    "D": (0,-1)
}
grid = [[0 for _ in range(10)] for _ in range(10)]
show_grid = True
idx = 0
trees = np.array(())
allP = np.array((0))
allS = np.array((0))
bounds = np.array(())
princess, shadow = np.array((0,0)), np.array((0,0))
plast, slast = np.array((0,0)), np.array((0,0))
moves = ""
n = 0
first = False

def move(command):
    global princess, shadow, idx, moves, trees, plast, slast, grid
    d = np.array(dirs[command])
    pp = princess + d
    ss = shadow + d
    # if (any(pp<0) or any(ss<0)):
    #     print("Invalid move!")
    #     return
    px, py = pp[0], pp[1]
    sx, sy = ss[0], ss[1]
    if grid[sy][sx] == 1:
        ss = shadow
    if grid[py][px] == 1:
        pp = princess
        ss = shadow
    princess = pp
    shadow = ss
    return

def next():
    global princess, shadow, idx, moves, trees, plast, slast, allP, allS, grid, n
    if idx == n:
        return
    idx+=1
    princess = allP[idx]
    shadow = allS[idx]
    return


def prev():
    global princess, shadow, idx, moves, trees, plast, slast, allP, allS, grid
    if idx == 0:
        return
    idx -= 1
    princess = allP[idx]
    shadow = allS[idx]
    return

class PlotApp:
    def __init__(self, root):
        global princess, shadow, idx, moves, trees, plast, slast, allP, allS, bounds, grid, n, first
        self.root = root
        self.root.title("Princess Game")
        #bounds = np.array(list(map(int, input().split())))
        B = 1000
        bounds = np.array([-B,B,-B,B])
        ins = list(map(int, input().strip().split()))
        px, py = ins[0], ins[1]
        sx, sy = ins[2], ins[3]
        T = ins[4]
        trees = np.zeros((T,2), dtype='int')
        for i in range(int(T)):
            tx, ty = map(int, input().split())
            trees[i] = np.array([tx,ty])
            trees[i] -= bounds[::2]

        princess = np.array((px,py))
        shadow = np.array((sx,sy))
        princess -= bounds[::2]
        shadow -= bounds[::2]

        moves = input().strip()
        
        grid = [[0 for _ in range(bounds[1] - bounds[0] + 1)] for _ in range(bounds[3] - bounds[2] + 1)]
        n = len(moves)
        if moves == "-1":
            n = 0
        allP = np.zeros((n+1,2), dtype='int')
        allS = np.zeros((n+1,2), dtype='int')
        allP[0] = princess
        allS[0] = shadow
        for i in range(T):
            try:
                grid[trees[i][1]][trees[i][0]] = 1
            except IndexError as err:
                print("Rand ist",bounds[0],bounds[1],bounds[2],bounds[3],sep=" ")
                print("Aber Baum platziert bei",trees[i][0]+bounds[0],trees[i][1]+bounds[2],sep=" ")

        #precompute all moves:
        for i in range(1,n+1):
            move(moves[i-1])
            allP[i] = princess
            allS[i] = shadow

        #compute min/max bound
        minL, minR, minD, minU = B, -B, B, -B
        for i in range(0,n+1):
            minL = min(minL, allP[i][0] + bounds[0], allS[i][0] + bounds[0])
            minD = min(minD, allP[i][1] + bounds[2], allS[i][1] + bounds[2])
            minR = max(minR, allP[i][0] + bounds[0], allS[i][0] + bounds[0])
            minU = max(minU, allP[i][1] + bounds[2], allS[i][1] + bounds[2])
        
        for i in range(T):
            minL = min(minL, trees[i][0] + bounds[0])
            minD = min(minD, trees[i][1] + bounds[2])
            minR = max(minR, trees[i][0] + bounds[0])
            minU = max(minU, trees[i][1] + bounds[2])
              
        #reset to og input:
        for i in range(int(T)):
            trees[i] += bounds[::2]
        for i in range(n+1):
            allP[i] += bounds[::2]
            allS[i] += bounds[::2]

        #adjust to new min bounds:
        bounds = np.array([minL,minR,minD,minU])
        for i in range(int(T)):
            trees[i] -= bounds[::2]
        for i in range(n+1):
            allP[i] -= bounds[::2]
            allS[i] -= bounds[::2]
        grid = [[0 for _ in range(bounds[1] - bounds[0] + 1)] for _ in range(bounds[3] - bounds[2] + 1)]
        for i in range(int(T)):
            grid[trees[i][1]][trees[i][0]] = 1

        #reset to 0:
        princess = allP[0]
        shadow = allS[0]

        print("init done")

        self.fig = plt.figure(figsize=(13,13))
        self.ax = self.fig.subplots()
        mymap = matplotlib.colors.ListedColormap(['white', 'black', 'purple', 'green', 'orange'])

        # Embed the plot in the tkinter window
        self.canvas = FigureCanvasTkAgg(self.fig, master=self.root)
        self.canvas_widget = self.canvas.get_tk_widget()
        self.canvas_widget.pack()

        # Generate the initial plot
        first = True
        self.update_plot()

        # Add "Previous" and "Next" buttons
        self.button_frame = tk.Toplevel(self.root)
        self.button_frame.attributes('-topmost', 'true')
        self.button_frame.protocol("WM_DELETE_WINDOW", sys.exit)

        helv = tk.font.Font(family='Helvetica', size=12)
        bh = 1
        bw = 8

        self.close_button = tk.Button(self.button_frame, text="End Sim", command=sys.exit)
        self.close_button.config(height = bh, width = bw, font = helv)
        self.close_button.pack(anchor = "s", side=tk.LEFT, padx=5, pady=5)

        self.first_button = tk.Button(self.button_frame, text="First", command=self.first_plot)
        self.first_button.config(height = bh, width = bw, font = helv)
        self.first_button.pack(anchor = "s", side=tk.LEFT, padx=5, pady=5)

        self.prev_button = tk.Button(self.button_frame, text="Previous", command=self.previous_plot)
        self.prev_button.config(height = bh, width = bw, font = helv)
        self.prev_button.pack(anchor = "s", side=tk.LEFT, padx=5, pady=5)

        self.next_button = tk.Button(self.button_frame, text="Next", command=self.next_plot)
        self.next_button.config(height = bh, width = bw, font = helv)
        self.next_button.pack(anchor = "s", side=tk.LEFT, padx=5, pady=5)

        self.last_button = tk.Button(self.button_frame, text="Last", command=self.last_plot)
        self.last_button.config(height = bh, width = bw, font = helv)
        self.last_button.pack(anchor = "s", side=tk.LEFT, padx=5, pady=5)

        self.root.bind("<Left>", self.previous_plot)
        self.root.bind("<Right>", self.next_plot)
        self.root.bind("<Up>", self.last_plot)
        self.root.bind("<Down>", self.first_plot)
        self.root.bind("g", self.change_grid)
        self.root.bind_all("<Control-c>", sys.exit)

    def update_plot(self):
        global princess, shadow, idx, moves, trees, plast, slast, bounds, grid, first, show_grid
        """Update the plot based on the current index."""
        self.ax.clear()  # Clear the previous plot
        mymap = matplotlib.colors.ListedColormap(['white', 'black', 'purple', 'green', 'orange'])
        #delete old positions of princess and shadow
        px, py = plast[0], plast[1]
        sx, sy = slast[0], slast[1]
        if (first):
            first = False
        else:
            grid[py][px] = 0
            grid[sy][sx] = 0
        
        #add new positions of princess and shadow
        px, py = princess[0], princess[1]
        grid[py][px] = 2
        sx, sy = shadow[0], shadow[1]
        if grid[sy][sx] == 2:
            grid[sy][sx] = 3
        else:
            grid[sy][sx] = 4

        #update lasts
        plast, slast = princess, shadow

        # Plot the data
        res = self.ax.imshow(grid, cmap=mymap, origin='lower')
        res.set_clim(0,4)
        plt.xticks([])
        plt.yticks([])
        # plt.xticks(range(bounds[0], bounds[1]+1, 10))  # Show ticks every 10 units
        # plt.yticks(range(bounds[2], bounds[3]+1, 10))
        self.ax.set_yticks(np.arange(0, bounds[3] - bounds[2]+1, 1), np.arange(bounds[2], bounds[3]+1, 1), minor=False)
        self.ax.set_xticks(np.arange(0, bounds[1] - bounds[0]+1, 1), np.arange(bounds[0], bounds[1]+1, 1), minor=False)
        A = np.arange(.5, bounds[3] - bounds[2], 1)
        B = np.arange(.5, bounds[1] - bounds[0], 1)
        self.ax.set_yticks(A, minor=True)
        self.ax.set_xticks(B, minor=True)
        self.ax.tick_params(bottom = False, left = False)
        if show_grid:
            self.ax.grid(which='minor', color="black", linestyle="-", linewidth=1)

        # Redraw the canvas
        self.canvas.draw()

    def next_plot(self, *args):
        """Go to the next plot."""
        next()
        self.update_plot()

    def previous_plot(self, *args):
        """Go to the previous plot."""
        prev()
        self.update_plot()

    def first_plot(self, *args):
        global princess, shadow, idx
        idx = 0
        princess = allP[0]
        shadow = allS[0]
        self.update_plot()
    
    def last_plot(self, *args):
        global princess, shadow, n, idx
        idx = n
        princess = allP[n]
        shadow = allS[n]
        self.update_plot()
    
    def change_grid(self, *args):
        global show_grid
        show_grid = not show_grid
        self.update_plot()

# Create the tkinter application
root = tk.Tk()
root.geometry('800x600')
root.protocol("WM_DELETE_WINDOW", sys.exit)
app = PlotApp(root)
root.mainloop()