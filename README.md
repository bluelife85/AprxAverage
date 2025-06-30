# AprxAverage
This is an approximate mean module based on computational convenience.
It is not a module that calculates a normal mean with a fixed window.
This module was created for use in microcontrollers that pursue memory lightness because it does not stack data in buffers.

# NOTE
This code is implemented based on standard integer (stdint).

# HOW TO USE
## Initialize
If you set the window size to 0, it will be set to the default size of 10.
<pre>
<code>
AAVG_Initialize(&testObj, 16);
</code>
</pre>

## Average
<pre>
<code>
average = AAVG_Averaging(&testObj, some_data);
</code>