#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;


#define WIDTH 10
#define HEIGHT 4

#define DEFAULT_STEP 0.001
#define MAX_VELOCITY_CHANGE 0.001

struct vector2d {
    double x, y;
}

typedef vector<vector<double> > data2d;


vector2d get_force(vector2d on, by);

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Usage: solve [time]\n";
        return 0;
    }
    
    unsigned double end_time = atoi(argv[1]);
    unsigned double time=0;
    double force;
    unsigned int i, j;
    data2d data;

    // Make a data array
    data.resize(WIDTH);
    for (i=0; i<data.size(); i++) {
        data[i].reserve(HEIGHT);
    }

    //Fill with stupid initial data
    for (i=0; i<data.size(); i++) {
        //Position x,y
        data[i][0] = 100;
        data[i][1] = 100;
        //Velocity x,y
        data[i][2] = 0;
        data[i][3] = 0;
    }

    //Try solving things :)
    while (time < end_time) {
        // Make a step here
        for (i=0; i<data.size(); i++) {
            // Calculate acceleration from each particle
            for (j=0; j<data.size(); j++) {
                
            }
        }
    }
}


vector2d get_force(vector2d on, by) {
    // Dummy function
    vector2d force;
    force.x = on.x;
    force.y = on.y;
    return force;
}
