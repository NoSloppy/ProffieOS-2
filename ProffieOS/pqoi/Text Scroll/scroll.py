#!/usr/bin/env python3
import sys
import os
import subprocess

# --- Environment Check ---
if sys.prefix == sys.base_prefix:
    print("Warning: You are running in the system Python environment.")
    print("It is recommended to use a virtual environment. For example:")
    print("    python3 -m venv env")
    print("    source env/bin/activate")
    print("    pip install Pillow numpy opencv-python")
    print()

# --- Module Imports ---
try:
    from PIL import Image, ImageDraw
except ImportError:
    sys.exit("Error: Pillow is not installed. Install it with: python3 -m pip install --user Pillow")
try:
    import numpy as np
except ImportError:
    sys.exit("Error: numpy is not installed. Install it with: python3 -m pip install --user numpy")
try:
    import cv2
except ImportError:
    sys.exit("Error: opencv-python is not installed. Install it with: python3 -m pip install --user opencv-python")

# --- ORIGINAL 5x7 Font Dictionary (non-mirrored) ---
ORIGINAL_FONT = {
    "A": ["01110", "10001", "10001", "11111", "10001", "10001", "10001"],
    "B": ["11110", "10001", "10001", "11110", "10001", "10001", "11110"],
    "C": ["01111", "10000", "10000", "10000", "10000", "10000", "01111"],
    "D": ["11110", "10001", "10001", "10001", "10001", "10001", "11110"],
    "E": ["11111", "10000", "10000", "11110", "10000", "10000", "11111"],
    "F": ["11111", "10000", "10000", "11110", "10000", "10000", "10000"],
    "G": ["01111", "10000", "10000", "10111", "10001", "10001", "01111"],
    "H": ["10001", "10001", "10001", "11111", "10001", "10001", "10001"],
    "I": ["01110", "00100", "00100", "00100", "00100", "00100", "01110"],
    "J": ["00111", "00010", "00010", "00010", "10010", "10010", "01100"],
    "K": ["10001", "10010", "10100", "11000", "10100", "10010", "10001"],
    "L": ["10000", "10000", "10000", "10000", "10000", "10000", "11111"],
    "M": ["10001", "11011", "10101", "10101", "10001", "10001", "10001"],
    "N": ["10001", "11001", "10101", "10011", "10001", "10001", "10001"],
    "O": ["01110", "10001", "10001", "10001", "10001", "10001", "01110"],
    "P": ["11110", "10001", "10001", "11110", "10000", "10000", "10000"],
    "Q": ["01110", "10001", "10001", "10001", "10101", "10010", "01101"],
    "R": ["11110", "10001", "10001", "11110", "10100", "10010", "10001"],
    "S": ["01111", "10000", "10000", "01110", "00001", "00001", "11110"],
    "T": ["11111", "00100", "00100", "00100", "00100", "00100", "00100"],
    "U": ["10001", "10001", "10001", "10001", "10001", "10001", "01110"],
    "V": ["10001", "10001", "10001", "10001", "10001", "01010", "00100"],
    "W": ["10001", "10001", "10001", "10101", "10101", "10101", "01010"],
    "X": ["10001", "10001", "01010", "00100", "01010", "10001", "10001"],
    "Y": ["10001", "10001", "01010", "00100", "00100", "00100", "00100"],
    "Z": ["11111", "00001", "00010", "00100", "01000", "10000", "11111"],
    "a": ["00000", "00000", "01110", "00001", "01111", "10001", "01111"],
    "b": ["10000", "10000", "10110", "11001", "10001", "10001", "11110"],
    "c": ["00000", "00000", "01111", "10000", "10000", "10000", "01111"],
    "d": ["00001", "00001", "01101", "10011", "10001", "10001", "01111"],
    "e": ["00000", "00000", "01110", "10001", "11111", "10000", "01110"],
    "f": ["00110", "01001", "01000", "11100", "01000", "01000", "01000"],
    "g": ["00000", "01111", "10001", "01111", "00001", "00001", "11110"],
    "h": ["10000", "10000", "10110", "11001", "10001", "10001", "10001"],
    "i": ["00100", "00000", "01100", "00100", "00100", "00100", "01110"],
    "j": ["00010", "00000", "00110", "00010", "00010", "10010", "01100"],
    "k": ["10000", "10000", "10010", "10100", "11000", "10100", "10010"],
    "l": ["11000", "01000", "01000", "01000", "01000", "01000", "01110"],
    "m": ["00000", "00000", "11010", "10101", "10101", "10101", "10101"],
    "n": ["00000", "00000", "10110", "11001", "10001", "10001", "10001"],
    "o": ["00000", "00000", "01110", "10001", "10001", "10001", "01110"],
    "p": ["00000", "00000", "11110", "10001", "11110", "10000", "10000"],
    "q": ["00000", "00000", "01111", "10001", "01111", "00001", "00001"],
    "r": ["00000", "00000", "10110", "11001", "10000", "10000", "10000"],
    "s": ["00000", "00000", "01111", "10000", "01110", "00001", "11110"],
    "t": ["01000", "01000", "11100", "01000", "01000", "01001", "00110"],
    "u": ["00000", "00000", "10001", "10001", "10001", "10011", "01101"],
    "v": ["00000", "00000", "10001", "10001", "10001", "01010", "00100"],
    "w": ["00000", "00000", "10001", "10101", "10101", "10101", "01010"],
    "x": ["00000", "00000", "10001", "01010", "00100", "01010", "10001"],
    "y": ["00000", "00000", "10001", "10001", "01111", "00001", "11110"],
    "z": ["00000", "00000", "11111", "00010", "00100", "01000", "11111"],
    "0": ["01110", "10001", "10011", "10101", "11001", "10001", "01110"],
    "1": ["00100", "01100", "00100", "00100", "00100", "00100", "01110"],
    "2": ["01110", "10001", "00001", "00010", "00100", "01000", "11111"],
    "3": ["01110", "10001", "00001", "00110", "00001", "10001", "01110"],
    "4": ["00010", "00110", "01010", "10010", "11111", "00010", "00010"],
    "5": ["11111", "10000", "11110", "00001", "00001", "10001", "01110"],
    "6": ["00110", "01000", "10000", "11110", "10001", "10001", "01110"],
    "7": ["11111", "00001", "00010", "00100", "01000", "01000", "01000"],
    "8": ["01110", "10001", "10001", "01110", "10001", "10001", "01110"],
    "9": ["01110", "10001", "10001", "01111", "00001", "00010", "01100"],
    "!": ["00100", "00100", "00100", "00100", "00000", "00000", "00100"],
    "?": ["01110", "10001", "00001", "00010", "00100", "00000", "00100"],
    ".": ["00000", "00000", "00000", "00000", "00000", "00110", "00110"],
    ",": ["00000", "00000", "00000", "00110", "00100", "00100", "01000"],
    ":": ["00000", "00110", "00110", "00000", "00110", "00110", "00000"],
    ";": ["00000", "00110", "00110", "00000", "00110", "00100", "01000"],
    "-": ["00000", "00000", "11111", "00000", "00000", "00000", "00000"],
    "_": ["00000", "00000", "00000", "00000", "00000", "00000", "11111"],
    "+": ["00000", "00100", "00100", "11111", "00100", "00100", "00000"],
    "=": ["00000", "11111", "00000", "11111", "00000", "00000", "00000"]
}

# --- Create a mirrored version for the Default style (used for Option 1) ---
def mirror_font(font_dict):
    mirrored = {}
    for char, pattern in font_dict.items():
        mirrored[char] = [row[::-1] for row in pattern]
    return mirrored

MIRRORED_FONT = mirror_font(ORIGINAL_FONT)

# --- Create a tall version by duplicating each row (used for Option 2) ---
def tallify(font_dict):
    tall_font = {}
    for char, pattern in font_dict.items():
        tall_pattern = []
        for row in pattern:
            tall_pattern.append(row)
            tall_pattern.append(row)
        tall_font[char] = tall_pattern
    return tall_font

# --- Helper: return a blank pattern of a given width ---
def blank_char(width):
    return ["0" * width]

# --- Attach external file data to a letter's pattern (with mirroring) ---
def attach_file_to_pattern(pattern, folder, letter, mirror_external=True):
    filename = os.path.join(folder, f"{letter.upper()}.txt")
    if os.path.exists(filename):
        try:
            with open(filename, "r") as f:
                extra_lines = f.read().splitlines()
            if mirror_external:
                extra_lines = [line[::-1] for line in extra_lines]
            return pattern + extra_lines
        except Exception as e:
            print(f"Warning: Could not read file for {letter}: {e}")
            return pattern
    else:
        return pattern

# --- Render text using the given font dictionary and attach external file data ---
def render_text(text, font_dict, attach_folder, letter_spacing=2, word_spacing=4, mirror_external=True):
    rendered_words = []
    for word in text.split(" "):
        letters = []
        for ch in word:
            base_pattern = font_dict.get(ch, font_dict.get(ch.upper(), blank_char(len(list(font_dict.values())[0][0]))))
            if attach_folder and os.path.isdir(attach_folder):
                full_pattern = attach_file_to_pattern(base_pattern, attach_folder, ch, mirror_external)
            else:
                full_pattern = base_pattern
            letters.append(full_pattern)
        if letters:
            max_height = max(len(letter) for letter in letters)
            padded_letters = []
            for letter in letters:
                width = len(letter[0])
                pad_count = max_height - len(letter)
                padded = letter + ["0" * width] * pad_count
                padded_letters.append(padded)
            combined = [list(row) for row in padded_letters[0]]
            for letter in padded_letters[1:]:
                for r in range(len(combined)):
                    combined[r].extend("0" * letter_spacing)
                    combined[r].extend(list(letter[r]))
            rendered_words.append(combined)
        else:
            rendered_words.append([list("0" * len(list(font_dict.values())[0][0]))])
    if rendered_words:
        combined = rendered_words[0]
        for word_img in rendered_words[1:]:
            for r in range(len(combined)):
                combined[r].extend("0" * word_spacing)
            for r in range(len(combined)):
                combined[r].extend(word_img[r])
        return combined
    else:
        return [list("0" * 5)] * 7

def pattern_to_image(pattern, text_color, background_color):
    height = len(pattern)
    width = len(pattern[0])
    img = Image.new("RGB", (width, height), background_color)
    draw = ImageDraw.Draw(img)
    for y, row in enumerate(pattern):
        for x, pixel in enumerate(row):
            if pixel == "1":
                draw.point((x, y), fill=text_color)
    return img

def hex_to_rgb(hex_color):
    hex_color = hex_color.strip().lstrip("#")
    if len(hex_color) != 6:
        raise ValueError("Invalid hex color. Use a 6-digit hex, e.g. #FFFFFF.")
    return tuple(int(hex_color[i:i+2], 16) for i in (0, 2, 4))

# --- Predefined Colors ---
COLORS = {
    "1": ("Black", "#000000"),
    "2": ("Blue", "#0000FF"),
    "3": ("White", "#FFFFFF"),
    "4": ("Red", "#FF0000"),
    "5": ("Green", "#00FF00"),
    "6": ("Yellow", "#FFFF00"),
    "7": ("Purple", "#800080"),
    "8": ("Pink", "#FFC0CB"),
    "9": ("Orange", "#FFA500"),
    "10": ("Teal", "#008080")
}

def choose_color(prompt, default_key):
    print(prompt)
    for key, (name, hex_code) in COLORS.items():
        print(f"  {key}: {name} ({hex_code})")
    choice = input(f"Enter your choice [{default_key}]: ") or default_key
    if choice not in COLORS:
        print("Invalid choice, using default.")
        choice = default_key
    selected_color = hex_to_rgb(COLORS[choice][1])
    print(f"Selected color: {COLORS[choice][0]} ({selected_color})")
    return selected_color

# --- Post-processing: Embed frame rate metadata using ffmpeg ---
def add_fps_metadata(filename, fps):
    temp_filename = filename.replace(".mp4", "_temp.mp4")
    command = [
        "ffmpeg",
        "-y",
        "-i", filename,
        "-r", str(fps),
        "-c", "copy",
        temp_filename
    ]
    try:
        subprocess.run(command, check=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        os.replace(temp_filename, filename)
        print("Frame rate metadata updated.")
    except Exception as e:
        print("Warning: Could not update frame rate metadata.", e)

# --- Create a mirrored preview file (flip every frame horizontally) ---
def create_mirrored_preview(input_filename, output_filename):
    cap = cv2.VideoCapture(input_filename)
    if not cap.isOpened():
        print("Error: Could not open input video for mirroring.")
        return
    fps = cap.get(cv2.CAP_PROP_FPS)
    width  = int(cap.get(cv2.CAP_PROP_FRAME_WIDTH))
    height = int(cap.get(cv2.CAP_PROP_FRAME_HEIGHT))
    fourcc = cv2.VideoWriter_fourcc(*'mp4v')
    out = cv2.VideoWriter(output_filename, fourcc, fps, (width, height))
    while True:
        ret, frame = cap.read()
        if not ret:
            break
        mirrored_frame = cv2.flip(frame, 1)
        out.write(mirrored_frame)
    cap.release()
    out.release()
    print(f"Mirrored preview saved as: {output_filename}")

# --- Generate Scrolling Animation Video (Right Scroll Only) ---
def generate_scrolling_text_video(text, text_color, background_color, font_dict, attach_folder, 
                                  scroll_speed=1, fps=10, output_filename="proffie_scroll.mp4", scale=1, mirror_external=True):
    # Force rightward scroll: reverse input text so that the original beginning appears first.
    text = text[::-1]
    rendered_pattern = render_text(text, font_dict, attach_folder, letter_spacing=2, word_spacing=4, mirror_external=mirror_external)
    text_img = pattern_to_image(rendered_pattern, text_color, background_color)
    
    base_height = len(rendered_pattern)
    frame_height = base_height + 2  # vertical padding
    frame_width = 9  # fixed base width
    frame_size = (frame_width, frame_height)
    
    text_width, text_height = text_img.size
    pad = fps  # 1-second blank buffer (columns)
    full_width = pad + text_width + pad
    full_canvas = Image.new("RGB", (full_width, frame_size[1]), background_color)
    vertical_offset = (frame_size[1] - text_height) // 2
    full_canvas.paste(text_img, (pad, vertical_offset))
    
    frames = []
    # For right scroll, crop frames with x decreasing.
    for x in range(full_width - frame_size[0], -1, -scroll_speed):
        frame = full_canvas.crop((x, 0, x + frame_size[0], frame_size[1]))
        frames.append(np.array(frame))
    
    if scale != 1:
        new_size = (frame_size[0] * scale, frame_size[1] * scale)
        upscaled_frames = []
        for frame in frames:
            upscaled = cv2.resize(frame, new_size, interpolation=cv2.INTER_NEAREST)
            upscaled_bgr = cv2.cvtColor(upscaled, cv2.COLOR_RGB2BGR)
            upscaled_frames.append(upscaled_bgr)
        frames = upscaled_frames
        final_frame_size = new_size
    else:
        final_frame_size = frame_size
        frames = [cv2.cvtColor(frame, cv2.COLOR_RGB2BGR) for frame in frames]
    
    if not output_filename.lower().endswith(".mp4"):
        output_filename += ".mp4"
    
    fourcc = cv2.VideoWriter_fourcc(*'mp4v')
    video = cv2.VideoWriter(output_filename, fourcc, fps, final_frame_size)
    if not video.isOpened():
        sys.exit("Error: Could not open video writer. Check output filename and codec settings.")
    for frame in frames:
        video.write(frame)
    video.release()
    print(f"Video saved to: {os.path.abspath(output_filename)}")
    
    add_fps_metadata(output_filename, fps)
    return output_filename

# --- Interactive Input Section ---
if __name__ == "__main__":
    script_dir = os.path.dirname(os.path.abspath(__file__))
    
    # --- Text Input ---
    text = input("Enter text to display [Proffie! Hello World 123]: ") or "Proffie! Hello World 123"
    
    # --- Font Style Selection ---
    print("Select font style:")
    print("  1: Default (built-in script font) - no external files")
    print("  2: Tall (mirrored tall version) - uses folder 'Pixel Text Font Tall'")
    print("  3: Normal (plain 5x7) - uses folder 'Pixel Text Font Normal'")
    style_choice = input("Enter your choice [1]: ") or "1"
    if style_choice == "1":
        # Option 1: Use the built-in default script font (MIRRORED_FONT) with no external attachments.
        chosen_font = MIRRORED_FONT
        attach_folder = None  # no external attachments
        mirror_external_flag = True  # flag not used when attach_folder is None
    elif style_choice == "2":
        chosen_font = tallify(MIRRORED_FONT)
        attach_folder = os.path.join(script_dir, "Pixel Text Font Tall")
        mirror_external_flag = True
    elif style_choice == "3":
        chosen_font = MIRRORED_FONT
        attach_folder = os.path.join(script_dir, "Pixel Text Font Normal")
        mirror_external_flag = True
    else:
        print("Invalid choice, using default (built-in script font).")
        chosen_font = MIRRORED_FONT
        attach_folder = None
        mirror_external_flag = True
    
    # --- Color Selection ---
    text_color = choose_color("Choose TEXT color:", "3")
    background_color = choose_color("Choose BACKGROUND color:", "1")
    
    print("Scroll direction is set to RIGHT automatically.")
    
    output_filename = input("Enter output file name [proffie_scroll.mp4]: ") or "proffie_scroll.mp4"
    try:
        fps = int(input("Enter frames per second (FPS) [15]: ") or "15")
    except ValueError:
        print("Invalid FPS, using default 15.")
        fps = 15
    try:
        scale = int(input("Enter preview scale factor (e.g., 10 for 90x90 preview) [10]: ") or "10")
    except ValueError:
        print("Invalid scale factor, using default 10.")
        scale = 10
    
    final_output = generate_scrolling_text_video(text=text, text_color=text_color, background_color=background_color,
                                  font_dict=chosen_font, attach_folder=attach_folder,
                                  scroll_speed=1, fps=fps, output_filename=output_filename, scale=scale,
                                  mirror_external=mirror_external_flag)
    
    # --- Option to Create Mirrored Preview ---
    make_mirrored = input("Create a mirrored preview file? (y/n) [n]: ") or "n"
    if make_mirrored.lower().startswith("y"):
        base, ext = os.path.splitext(final_output)
        preview_filename = f"{base}_preview{ext}"
        create_mirrored_preview(final_output, preview_filename)