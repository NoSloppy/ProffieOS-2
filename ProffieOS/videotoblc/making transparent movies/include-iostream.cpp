#include <iostream>
#include <string>

using namespace std;

int main() {
string movie_filename;
cout << "Enter the movie filename: ";
cin >> movie_filename;

string command = "ffmpeg -i " + movie_filename + " -vf format=rgba,split[s0][s1];[s0]crop=iw/2:ih:0:0[left];[s1]crop=iw/2:ih:iw/2:0[right];[left]lutrgb=r=gammaval(.45)[left_gamma];[right]lutrgb=r=gammaval(.45)[right_gamma];[left_gamma][right_gamma]alphamerge output.blc";
system(command.c_str());

return 0;
}




