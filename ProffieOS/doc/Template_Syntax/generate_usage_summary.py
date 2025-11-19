import os
import re
import random

def extract_usage_comments():
    directory = os.getcwd()
    directory_name = os.path.basename(directory)
    output_file = f"{directory_name}_usage_summary.md"

    markdown_output = [
        "---",
        f"title: {directory_name.capitalize()} Template Syntax Summary",
        "---",
        "",
        f"Here’s a summary list of all of the \"Usage:\" comment sections from the header files in {directory_name}.",
        "",
    ]

    usage_regex = re.compile(r"// Usage: (.+)")
    or_regex = re.compile(r"// or: (.+)")
    details_regex = re.compile(r"// (.+)")

    examples = []

    for filename in sorted(os.listdir(directory)):
        if filename.endswith(".h"):
            file_path = os.path.join(directory, filename)
            with open(file_path, "r") as file:
                lines = file.readlines()

            usage_lines = []
            commands = []
            current_usage_block = []
            inside_usage_block = False

            for line in lines:
                match_usage = usage_regex.match(line)
                match_or = or_regex.match(line)
                match_detail = details_regex.match(line)

                if match_usage:
                    command = match_usage.group(1).split("<")[0]
                    commands.append(command)
                    if not inside_usage_block and current_usage_block:
                        usage_lines.append("\n".join(current_usage_block))
                        current_usage_block = []
                    current_usage_block.append(f"Usage: {match_usage.group(1)}")
                    examples.append(match_usage.group(1))
                    inside_usage_block = True
                elif match_or and inside_usage_block:
                    command = match_or.group(1).split("<")[0]
                    commands.append(command)
                    current_usage_block.append(f"or: {match_or.group(1)}")
                elif match_detail and inside_usage_block:
                    current_usage_block.append(match_detail.group(1))
                elif inside_usage_block:
                    usage_lines.append("\n".join(current_usage_block))
                    current_usage_block = []
                    inside_usage_block = False

            if current_usage_block:
                usage_lines.append("\n".join(current_usage_block))

            if usage_lines and commands:
                commands_header = ", ".join(commands)
                file_url = f"https://github.com/profezzorn/ProffieOS/blob/master/{directory_name}/{filename}"
                markdown_output.append(f"## [{commands_header}]({file_url})")
                markdown_output.extend(usage_lines)
                markdown_output.append("")

    if examples:
        example = random.choice(examples)
        markdown_output.insert(5, f"\nFor example, if you were looking for what arguments {example.split('<')[0]}<> takes,  \n"
                                  f"now you’d know that it takes {example}.  \n")

    with open(output_file, "w") as out_file:
        out_file.write("\n".join(markdown_output))
    print(f"Markdown document generated: {output_file}")

extract_usage_comments()
