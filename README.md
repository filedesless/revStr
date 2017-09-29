# revStr

revStr is a very simple command line tools much inspired by BSD's rev command. It was created as an attempt to entertain myself on a chillish day.

### Usage
It simply reads from file(s) passed as arguments (or stdin) line by line, and outputs the reversed line. Example usage is as follow:

```shell
filedesless@AirBook:~$ cat words.txt 
hello
darkness my old friend
filedesless@AirBook:~$ ./rev words.txt 
olleh
dneirf dlo ym ssenkrad
filedesless@AirBook:~$ cat words.txt | ./rev
olleh
dneirf dlo ym ssenkrad
```

### Why?
It differs from a traditionnal rev implementation in the aspect that it's written in C++ instead of plain old C (which admittedly makes it heavier). It _should_ compile without a itch on c++98 compilers or newer, and not generate warnings with pretty much any -W flag I could think of.

It was only tested on OSX, but _should_ compile fine on Windows/Linux; waiting for feedback on this.

It is also worth noting an added (artificial) constraint was taken into account while developping revStr. It's that I obviously had to use some sort of swap() like the templated function from \<algorithm> std::reverse, but I decided to make it unusual in the sense that it would not require **any** temporary variable to hold an element while swapping. This implementation relies on XOR's properties to reverse a string without the need for any more memory.