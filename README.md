# Linux-Shell

* Linux Command Line project built as an assignment for the Operating Systems course @IIIT-Delhi


## Getting Started

* Clone the git repository
```
git clone https://github.com/Madhur-iiitd/Linux-Shell.git
```


### Prerequisites

* Linux based os required
* Tested on Ubuntu, Artix and Kali-Linux based WSL


### Installation

* Run the makefile to compile the C files
```
make
```

* Run the main_shell for starting up the Command Line
```
./main_shell
```

## Usage

* In the Main Shell, simply type out the commands like these(refer to commands and tags)

```
cd ..
```
```
ls -a
```
```
mkdir new_folder
```
```
rm -d new_folder
```

## Commands and Tags
| Command      | Flags        | Description                              | Usage of Tags                                  |
|--------------|--------------|------------------------------------------|------------------------------------------------|
| echo         | -E , -n      | Display a line of text                   | Use -E to interpret backslashes (\)            |
| pwd          | -            | Print the current working directory      | No specific tags                               |
| cd           | -L           | Change the current directory             | Use -L to follow symbolic links when changing directories |
| rm           | -i , -d      | Remove files or directories              | Use -i for interactive prompt, -d to remove directories |
| mkdir        | -v , -p      | Create directories                       | Use -v for verbose output, -p for creating parent directories if needed |
| ls           | -A , -a , -i | List files and directories               | Use -A to list almost all files, -a for all files including hidden, -i for inode numbers |
| date         | -R , -u      | Display or set the system date and time  | Use -R for RFC 2822 formatted date, -u for UTC time |
| cat          | -v , -E      | Concatenate and display file content    | Use -v to show non-printing characters, -E to display $ at the end of each line |




