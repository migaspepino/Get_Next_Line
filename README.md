# Get_Next_Line
##### (Version: 10)

## 1. Summary
This project is about programming a function that returns a line  
read from a file descriptor

Version: 10

<br/>

## 2. Return
 * Repeated calls (e.g., using a loop) to `get_next_line()` should let you read the text file pointed to by the file descriptor,  one line at a time.  
 * Returns the line that was read. If there is nothing else to read or if an error occurred, it returns `NULL`.
 * The returned line includes the terminating `\n` character,  
except if the end of file was reached and does not end with a `\n` character.

## 3. Flowchart
![flowchart](https://raw.githubusercontent.com/mimarque/Get_Next_Line/main/GNL_flowchart.png)
