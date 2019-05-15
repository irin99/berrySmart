import plotly.plotly as py
import plotly.graph_objs as go

import requests
import numpy as np

URL = "http://608dev.net/sandbox/sc/garciag/all_dataHandler.py"
r = requests.get(url=URL)
data = eval(r.text)

temp1 = data[0]
temp2 = data[1]
temp3 = data[2]

N = len(data)
random_x = np.linspace(0, 10*N, N)

# Create traces
trace0 = go.Scatter(
    x = random_x,
    y = temp1,
    name = 'Plot 1',
    mode = 'lines+markers'
)
trace1 = go.Scatter(
    x = random_x,
    y = temp2,
    name = 'Plot 2',
    mode = 'lines+markers'
)
trace2 = go.Scatter(
    x = random_x,
    y = temp3,
    name = 'Plot 3',
    mode = 'lines+markers'
)

data = [trace0, trace1, trace2]
layout = dict(title = 'Temperature',xaxis = dict(title = 'Time (min)'), yaxis = dict(title = 'Degrees Celsius'))
fig = go.Figure(data = data, layout = layout)
py.plot(fig)