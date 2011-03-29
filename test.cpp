#include <iostream>
#include <vector>
#include <stdlib.h>
#include <cmath>

using namespace std;


#define WIDTH 10
#define HEIGHT 4

#define DEFAULT_STEP 0.001
#define MAX_VELOCITY_CHANGE 0.001
#define MASS 0.001

struct vector2d {
    double x, y;
};

typedef vector<vector<double> > data2d;


vector2d get_force(vector2d on, vector2d by);

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Usage: solve [time]\n";
        return 0;
    }
    
    double end_time = atoi(argv[1]);
    double time=0;
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
    vector2d on, by;
    vector2d force, acceleration;
    while (time < end_time) {
        // Make a step here
        cout << time << " ";
        for (i=0; i<data.size(); i++) {
            cout << data[i][0] << " " << data[i][1] << " "; 

            on.x = data[i][0];
            on.y = data[i][1];
            
            // Calculate acceleration from each particle
            acceleration.x = 0;
            acceleration.y = 0;

            for (j=0; j<data.size(); j++) {
                by.x = data[j][0];
                by.y = data[j][1];
                
                // Calculate force
                force = get_force(on, by);
                
                // Add to acceleration of current particle
                acceleration.x += force.x / MASS;
                acceleration.y += force.y / MASS;
            }

            // Add to velocity x,y
            data[i][2] += acceleration.x * DEFAULT_STEP;
            data[i][3] += acceleration.y * DEFAULT_STEP;

            // Change position
            data[i][0] += data[i][2] * DEFAULT_STEP;
            data[i][1] += data[i][3] * DEFAULT_STEP;

        }
        cout << "\n";
        
        time += DEFAULT_STEP;
    }
}


inline vector2d get_force(vector2d on, vector2d by) {
    // Dummy function
    vector2d force;

    double r = sqrt((on.x-by.x)*(on.x-by.x) + (on.y-by.y)*(on.y-by.y));
    double f = 6*(pow(r,6) - 2) / pow(r,13);

    force.x = (f/r)*(on.x - by.x);
    force.y = (f/r)*(on.y - by.y);

    return force;
}
