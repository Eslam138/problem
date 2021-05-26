#include <bits/stdc++.h>
using namespace std;

int diskShedular(int tracksArray[] ,int arraySize ,int h)
{
    sort(tracksArray, tracksArray+arraySize);

	int seek_sum = 0;
	int dis, currentT;

	if (abs(h-tracksArray[0]) < abs(h-tracksArray[arraySize-1])) { //if the stating head position is closer to the first array element

        for (int i=0; i<arraySize; i++) {
            currentT = tracksArray[i];

            dis = abs(currentT - h);
            seek_sum = seek_sum + dis;

            h = currentT;
          }
    }
    else {  //if it is closer to the last element re order in descending order
            sort(tracksArray, tracksArray+arraySize, greater<int>());

            for (int i=0; i<arraySize; i++) {
                currentT = tracksArray[i];

                dis = abs(currentT - h);
                seek_sum = seek_sum + dis;

                h = currentT;
          }
    }
	return seek_sum;
}

int main()
{

	int tracksArray[] = {100 ,50 ,190};
	int arraySize = sizeof(tracksArray) / sizeof(tracksArray[0]);
	int HEAD = 140 ;

	int seek = diskShedular (tracksArray, arraySize, HEAD);
	cout << "The total minimal seek time = "<< seek << endl;
	return 0;
}
