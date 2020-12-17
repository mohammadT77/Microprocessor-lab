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

