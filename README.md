# Microprocessor-lab
Microprocessor-Lab assignments Repository - Kharazmi University

## Assignment #1: blinking LEDs
* problem 1: Implement in the source</br>
* problem 2: Implement in the source</br>
* problem 3: Implement in the source</br>
* problem 4: [Problem4,5.pdf](https://github.com/mohammadT77/Microprocessor-lab/blob/main/Assignment%201/Problem4%2C5.pdf)</br>
* problem 5: [Problem4,5.pdf](https://github.com/mohammadT77/Microprocessor-lab/blob/main/Assignment%201/Problem4%2C5.pdf)</br>

## Assigment #2: 7Segs and Timers
* problem 1: [Commit: Implelemt Problem 1](https://github.com/mohammadT77/Microprocessor-lab/commit/4c1b6cc12d4f7af68b54ee156ab85b71ba0c2ca2#diff-e29be61e4c8f7a80296141a23f1752641e1e4e036db5e00ac912dac012977061)
* problem 2: Final project

**Note:** Calculating FPS (Frame per second) or Recommended Frequency for Timer 0
```
  FPS Calculate:
  "human eye can see between 30 and 60 frames per second."
  So we should use 4*(TARGET_FPS) for , because we have 4 BCD (FPS /4 recieveid by every BCD)
    
  > Timer0 Freq = 8 MHz / 1024(prescaler) = 7812 Hz
  
  Then:
  > Timer0_value = Timer0_freq / 4 * TARGET_FREQ
    
  So we've:     
  - 0 for Max(1953) FPS Per BCD
  - 256 for Min(7) FPS Per BCD
  - 65 for 30FPS Per BCD
  - 32 for 60 FPS Per BCD
```


## Assigment #3: LCD and Timers
* problem 1: [Commit: Complete Problem 1](https://github.com/mohammadT77/Microprocessor-lab/commit/f4482e76ff24037381bc8d805cc6d1a434e5d36b#diff-569436c85f4ed36b30f4aa216d0eca79c9b49aeedb84954e3447ae20f0b0df0c)
* problem 2: [Commit: Complete Problem 2](https://github.com/mohammadT77/Microprocessor-lab/commit/c42d30912c79c0e707bb7b6d2478d131947b0759#diff-569436c85f4ed36b30f4aa216d0eca79c9b49aeedb84954e3447ae20f0b0df0c)
* problem 3: Final Version - 'Hello World!' will be displayed on the LCD at first, then if 'ENABLE ICP1' switch is open (disable) : Alphabets will be displayed on the LCD else LCD Show Period and Frequency of the Input wave on Pin (20).


## Assigment #4: Stepper Motor
[Screen shots and Recording Directory Link](https://github.com/mohammadT77/Microprocessor-lab/tree/main/Assignment%204/screenshots)
![Assignment4:big picture](https://raw.githubusercontent.com/mohammadT77/Microprocessor-lab/main/Assignment%204/screenshots/1-description.png)
* problem 1: [Commit: Init Assignment 4 - Problem 1](https://github.com/mohammadT77/Microprocessor-lab/commit/14443fa5e9d31c1f77abe36b5661ba9ff4a4ab6e#diff-d466de186dc6b083efc205d05a7459037ba4ca8a25bb94abd77749ecf0ff0430)
* problem 2: [Commit: Assignment4-problem2](https://github.com/mohammadT77/Microprocessor-lab/commit/5d9e5441af1b93da1a86684425cef21221876033#diff-d466de186dc6b083efc205d05a7459037ba4ca8a25bb94abd77749ecf0ff0430)
* problem 3: [Commit: Assignment 4 - Problem 3](https://github.com/mohammadT77/Microprocessor-lab/commit/e6d175e401cc6629f4083c92d4979794f3409602#diff-d466de186dc6b083efc205d05a7459037ba4ca8a25bb94abd77749ecf0ff0430)
* problem 4: Final version - [Screen record Link](https://github.com/mohammadT77/Microprocessor-lab/raw/main/Assignment%204/screenshots/Rec%202021-01-10%200003.mp4)
![Calculate Speed and Acceleration](https://raw.githubusercontent.com/mohammadT77/Microprocessor-lab/main/Assignment%204/screenshots/3-started.png)

