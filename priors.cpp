#include <iostream>
#include <vector>
#include <numeric>

using std::vector;

// initialize priors assuming vehicle at landmark +/- 1.0 meters position stdev
vector<float> initialize_priors(int map_size, vector<float> landmark_positions,
                                float position_stdev);

int main() {
  // set standard deviation of position
  float position_stdev = 1.0f;

  // set map horizon distance in meters 
  int map_size = 25;

  // initialize landmarks
  vector<float> landmark_positions {5, 10, 20};

  // initialize priors
  vector<float> priors = initialize_priors(map_size, landmark_positions,
                                           position_stdev);

  // print values to stdout 
  for (int p = 0; p < priors.size(); ++p) {
    std::cout << priors[p] << std::endl;
  }

  return 0;
}

// TODO: Complete the initialize_priors function
vector<float> initialize_priors(int map_size, vector<float> landmark_positions,
                                float position_stdev) {

  // initialize priors assuming vehicle at landmark +/- 1.0 meters position stdev
  // set all priors to 0.0
  vector<float> priors(map_size, 0.0);
  // TODO: YOUR CODE HERE
  int i;
    for(i = 0; i < landmark_positions.size(); i++ )
    {   
        priors[landmark_positions[i]] += 1;
        if (landmark_positions[i] != 1) priors[landmark_positions[i] - 1] += 1;
        if (landmark_positions[i] != map_size-1) priors[landmark_positions[i] + 1] += 1;
    }
        int count = accumulate(priors.begin(), priors.end(), 0);
    
    for(i = 0; i < priors.size(); i++ )
        priors[i] /= count;

  return priors;
}