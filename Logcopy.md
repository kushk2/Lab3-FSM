note: command+shift+v for Preview
---

# Friday 12th October
### Lab1 Task 1 - *Simulate Basic Binary Counter*


- Made counter.sv module (clk, en, rst, 8 bit count; always_ff(if rst, count =0, else count+=1)
- Compiled and verified the result in GTwave with the vcd file produced
- made doit.sh to run the compile process quicker

---

# Monday 24th October

### Lab1 Task 2 - *Linking Verilator sim with VBuddy*

- Connected to vbuddy via USB 
- ran doit.sh for modified code
- couldn't get anything other than the self test options to come up on the Vbuddy, no impact on the 7sig test nor when plotting - said connected via port but this didnt change when disconnected and reconnected



# Tuesday 25th October 

### Lab1 Task 2

- Connected with different vbuddy and different adapter
- connected to vbuddy (self test was on) and counter worked

---

# Friday 28th October

### Lab1 Task 2

- Broke the vbuddy
- Task2 Counter working and enable flag working (counter_tb.cpp)
- Task2 Challenge completed and counting up and down working
- Started Task3 (optional), single shot worked (vbdSetMode(1)), vbdValue() found to get val of rot encoder, code incomplete though

### *Lab1 COMPLETE*

***

# Monday 31st October 

### Lab 2 Task 1 - *Simple Sine Wave Generator (ROM)*

- Started Lab2, copied code from slides
    - $readmemh("sinerom.mem", rom_array);
    - allows the ROM to be laoded with the contents stored in a file with numbers stroed as hexidecimal code in the file named "sinerom.mem"
- First use of vbdGetKey() = 'q', to exit

---

# Wednesday 2nd Nov

### Lab 2 Task 1

- Continues with Lab2 Task1
    - 1'b0 represents 1 bit binary of value 0
    - '>>' and '<<' operators represent a shift (c++)
- Used Lab1 files and adapted to create a working test bench, similarly with the doit.sh file, which all worked as expected
- some issues with defining incr which were fixed later (must initialise in top level with top->incr = x, at start of (body) testbench, alongside en, rst, etc.)

### Lab2 Task 1 COMPLETE 

---

# Thursday 3rd Nov

### Lab 2 Task 2 - *Sine & Cosine Dual wave gen*

- rom changes: 
    - 2x inputs for addr1 & addr2
    - 2x outputs for dout1 & dout2
    - New input called offset added, dout
    - in always_ff: dout1 as normal, dout2 as addr + offset
- counter as simple counter
- sinegen.sv
    - input offset added
    - count wired to address
    - address wired to both dout1 and dout2
    - offset mapped in sineRom
- sinegen_tb
    - top->offset initialised to 0
    - vbdPlot for both dout1 and 2, between 0-255

- Working - but phase shift unclear, 64 offset not working
    - Fix - top->offset = vbdValue() + 128;, inital value is 128
    - Working fully, cosine and sine  (2 signals) are perfectly pi/2 out of phase
    - Note, counter seems to reset at very beginning of plot, where it starts plot again, this was top->rst = (i < 2 || i == 16);
    - Deleting i==16 so it keeps going after i < 2 resets it once

### *Lab2 Task2 COMPLETE*

---

# Friday 4th November 

# Lab 2 Task 3 - *Capture & Display Audio Signal in RAM*

- RAM because it can be written and read throughout the simulation
- made top level module as such:
    ![image info](./Lab2-SigGen/images/topmodulediagram.jpg)

- RAM:
    - read and write enable (as well as clocked)
    - read address and write address 
    - data in and data out

    - If *wr_en = 1*, we want to input *data_in* to the slot of RAM specified by the *write_address* (input)
    - If *rd_en = 1*, we want to output from the RAM at address *read_address*,  through *dout* output

    - Nothing special is put here for our specific funtionaility
    
- Counter
    - We want to access the RAM at any any offset we specify, e.g if the clock is at 1,2,3,4,5, we can feed this into the write address, but if we want to read X values behind, we may want to wait til the 11,12,13,14,15 til we read those values (X = 10 in this case)
    - To do this, we want a counter which counts normally (count1 <= count1 + 1)
    - and a 2nd counter which takes count1 <= count1 - offset
        - This keeps incrementing up by 1, but lags behind by an offset

- Top Level Module (sigdelay)
    - We can feed the first counter into the *write_address*, as we always want to be writing to the RAM live
    - The second counter can be fed to the *read_address*, so that we can either read live (1 delay) or behind by X offset (defined by the value of the rotary encoder 0-100)
    - Other inputs/connections are intuitive

- Test bench
    - Most provided to us, note that dout will give us the offset read of the microphone signal (delayd)
    - If we read the data going INTO the rom, we can easily see the live data of the microphone

- Observations:
    - The microphone was not very accurate at all, and noise was not really discernable, but it was clear to see a 2 seperate plots (where 1 was the copy of the other)

### *Lab2 Task3 Complete*
### *Lab2 Complete*

---

### Lab 3 Task 1 - *4 Bit LFSR Psuedo Random*

- Made LSFR module (Linear Feedback Shift Register)
    - ![image info](./Lab3-FSM/images/lfsr.jpg)
    - generates a psuedo random binary sequence (pseudo random because it repeats itself every 2^N -1, for an N bit long number generator)
    - ![image info](./Lab3-FSM/images/lsfrtable.jpeg)
    -Left shifts (LSB->LSB + 1), and XORs [3] and [4] togethe to get the new LSB
    - dout is all 4 bits (so we can display hex and light bar)

- doit.sh & tb modified from earlier versions - both trivial
    - en = 1, rst = 0, en = vbdFlag & flag in single shot mode to step through

### *Lab 3 Task 1 Complete*

---

# Monday 7th November

### Lab 3 Task 2

- Made F1 Light Sequence Module (sv):
    - ![image info](./Lab3-FSM/images/state_diag.jpg)
    - Initialse values as normal (keep clk although unused, as it is used in the testbench)
    - typedef - define variable of type __
    - enum - refer to a list of string values as integers internally, but allow the user/programmer to refer to them by their string names. s0, s1 are stored as 0,1 but referred to as s0 and s1 in the code for the user - using '0' and '1' in the code itself would be problematic as these are "magic numbers"
    - set always_FF
    - define combinational logic for which state is next, and under which condition (case(currentstate)), remember to include **default**
    - ![image info](./Lab3-FSM/images/f1currstatecode.png)
    - define comb logic for output (according to state), again including default
    - ![image info](./Lab3-FSM/images/f1doutstatecode.png)
- Modify testbench from previous task, display top->dout on vbdBar

# Lab 3 Task 2 Complete

# Lab 3 Task 3 - *clktick.sv module*

- Completed as per instructions - find N such that VBar flashes at same rate as 60bpm (1 flash a second)
- Found N = 25
- Why? 

---
