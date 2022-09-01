//
//  main.cpp
//  Img Blurrer
//
//  Version 0.0.1
//
//  Created by Logan Levitre on 8/30/22.
//

#include <iostream>
#include <stdio.h>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <filesystem>
#include <unistd.h>
#include <sstream>

using namespace std;
using namespace cv;

int main(int argc, const char * argv[])
{
 
    bool exit = false;
    int input = 0;
    string chosenImg;
    stringstream header;
    while(!exit)
    {
        
        cout << "What would you like to do?\n";
        cout << "1.Blur\n" << "2.Invert\n" << "3.Grey\n" << "4.Exit\n";
        cout << ">>> ";
        cin >> input;
        if(input == 1)
        {
            cout << "enter a filename: ";
            cin >> chosenImg;
            const string srcPath = "Resources/"+ chosenImg;
            cout << srcPath << "\n";
  
            // Load img
            Mat inputImg = imread(srcPath);
            // check if img load was sucessful
            if(!inputImg.data)
            {
                cout << "Error could not open/find the image. \n";
            }
            else
            {
                
                Mat outputImg;
                int blurSizeX = 0;
                int blurSizeY = 0;
                cout << "Enter width and height of output: ";
                cin >> blurSizeX >> blurSizeY;
                header << "Output: " << blurSizeX << "x" << blurSizeY << "Blur";
                startWindowThread();
                if(blurSizeY <= 5 && blurSizeX <= 5 )
                {
                    blur(inputImg, outputImg, Size(10,10));
                    namedWindow(header.str());
        
                    imshow(header.str(), outputImg);
                    waitKey(0);
                    destroyWindow(header.str());
                    waitKey(1);
                }
                else
                {
                    blur(inputImg, outputImg, Size(blurSizeX,blurSizeY));
                    //header << "Output: " << blurSizeX << "x" << blurSizeY;
                    namedWindow(header.str());

                    imshow(header.str(), outputImg);
                    waitKey(0);
                    destroyWindow(header.str());
                    waitKey(1);
                }
            }
        
        }
        else if(input == 2)
        {
            cout << "enter a filename: ";
            cin >> chosenImg;
            const string srcPath = "Resources/"+ chosenImg;
            cout << srcPath << "\n";
  
            // Load img
            Mat inputImg = imread(srcPath);
            // check if img load was sucessful
            if(!inputImg.data)
            {
                cout << "Error could not open/find the image. \n";
            }
            else
            {
                // Invert img by inverting all bits of img
                inputImg = ~inputImg;
                // Another way of inverting img:
                // inputImg = Scalar(255,255,255) - inputImg;
                startWindowThread();
                namedWindow("Output: Inverted");

                imshow("Output: Inverted", inputImg);
                waitKey(0);
                destroyWindow("Output: Inverted");
                waitKey(1);
            }
        }
        
        else if(input == 3)
        {
            cout << "enter a filename: ";
            cin >> chosenImg;
            const string srcPath = "Resources/"+ chosenImg;
            cout << srcPath << "\n";
  
            // Load img
            Mat inputImg = imread(srcPath);
            // check if img load was sucessful
            if(!inputImg.data)
            {
                cout << "Error could not open/find the image. \n";
            }
            else
            {
                
                cvtColor(inputImg, inputImg, COLOR_BGR2GRAY);
                startWindowThread();
                namedWindow("Output: Grey");

                imshow("Output: Grey", inputImg);
                waitKey(0);
                destroyWindow("Output: Grey");
                waitKey(1);
            }
            
        }
        
        else if(input == 4)
            exit = true;
    }
    cout << "Goodbye!\n";
    return 1;
}
