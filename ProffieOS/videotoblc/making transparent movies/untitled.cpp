#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>

using namespace std;

int main(int argc, char** argv)
{
// Check that the correct number of arguments were passed
if (argc < 2)
{
cout << "Usage: " << argv[0] << " movie_file" << endl;
return 1;
}

// Open the movie file
ifstream movie(argv[1], ios::binary);
if (!movie)
{
    cout << "Error opening movie file" << endl;
    return 1;
}

// Create the output BLC file
ofstream blc("transparent.BLC", ios::binary);
if (!blc)
{
    cout << "Error creating BLC file" << endl;
    return 1;
}

// Read the movie file one frame at a time
char* frame = new char[1024*1024]; // allocate 1MB for each frame
while (movie.read(frame, 1024*1024))
{
    // Use ffmpeg to transform the frame
    string cmd = "ffmpeg -i " + string(frame) + " -vf \"scale=iw/2:ih/2\" -y temp.BLC";
    system(cmd.c_str());

    // Read the transformed frame from temp.BLC
    ifstream temp("temp.BLC", ios::binary);
    if (!temp)
    {
        cout << "Error opening temp.BLC file" << endl;
        return 1;
    }
    temp.read(frame, 1024*1024);

    // Write the transformed frame to the output BLC file
    blc.write(frame, 1024*1024);

    // Delete the temp.BLC file
    temp.close();
    remove("temp.BLC");
}

// Clean up
delete[] frame;
blc.close();
movie.close();

return 0;
}