# This file generates a wav of the specified ProffieOS beep sequence.
# run with `python beep_player.py'


import numpy as np
import wave

def generate_beep(duration, frequency, sample_rate=44100):
    t = np.linspace(0, duration, int(sample_rate * duration), endpoint=False)
    waveform = 0.5 * np.sin(2 * np.pi * frequency * t)
    return waveform

def save_wave(filename, data, sample_rate=44100):
    data = np.int16(data * 32767)
    with wave.open(filename, 'w') as wf:
        wf.setnchannels(1)
        wf.setsampwidth(2)
        wf.setframerate(sample_rate)
        wf.writeframes(data.tobytes())

beeps = [

(0.20, 1000.0),
(0.20, 1414.2),
(0.20, 2000.0)
]

sample_rate = 44100
result = np.array([])

for duration, frequency in beeps:
    beep = generate_beep(duration, frequency, sample_rate)
    result = np.concatenate((result, beep))

save_wave('beep_sequence.wav', result, sample_rate)
