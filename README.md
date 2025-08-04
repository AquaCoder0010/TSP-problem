# TSP-problem

Naive approach to solving the Traveling Salesman Problem.

Start by first installing SFML

<pre> sudo apt install libsfml-dev </pre>

then compile the project using the following g++ compilation flags
<pre>
g++ -std=c++23 *.cpp -o output -I include -L/usr/lib/x86_64-linux-gnu -lsfml-graphics -lsfml-window -lsfml-system
</pre>

then run the output file
<pre>
./output
</pre>