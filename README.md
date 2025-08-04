# TSP-problem

Naive approach to solving the Traveling Salesman Problem.

Start by first installing SFML
'''bash
sudo apt install libsfml-dev
'''

then compile the project using the following g++ compilation flags
'''bash
g++ -std=c++23 *.cpp -o output -I include -L/usr/lib/x86_64-linux-gnu -lsfml-graphics -lsfml-window -lsfml-system
'''

then run the ./output file
'''bash
./output
'''