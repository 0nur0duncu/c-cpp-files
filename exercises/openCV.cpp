//"C:\\Users\\onur\\Desktop\\cppFreeSpace\\saricember.mp4"

#include <opencv2/opencv.hpp>

using namespace cv;

int main()
{
    // Open the video file
    VideoCapture cap("C:\\Users\\onur\\Desktop\\cppFreeSpace\\saricember.mp4");

    // Check if video file opened successfully
    if (!cap.isOpened()) {
        std::cerr << "Error opening video file\n";
        return -1;
    }

    // Create a window to display the video
    namedWindow("Video", WINDOW_AUTOSIZE);

    while (true) {
        // Read a frame from the video
        Mat frame;
        if (!cap.read(frame))
            break;

        // Convert the frame to grayscale
        Mat gray;
        cvtColor(frame, gray, COLOR_BGR2GRAY);

        // Apply a blur to reduce noise
        //GaussianBlur(gray, gray, Size(5, 5), 0, 0);
        medianBlur(gray, gray, 5);
        // Detect circles in the frame
        std::vector<cv::Vec3f> circles;
        HoughCircles(gray, circles, HOUGH_GRADIENT, 1,
                    gray.rows/16,  // change this value to detect circles with different distances to each other
                    100, 30, 180, 250 // change the last two parameters
                // (min_radius & max_radius) to detect larger circles
        );
        //cv::HoughCircles(gray, circles, cv::HOUGH_GRADIENT, 1, gray.rows / 16, 100, 30, 1, 30);
        //HoughCircles(gray, circles, HOUGH_GRADIENT, 1, gray.rows/8, 200, 100, 0, 0);
        // Draw the circles on the frame
        /* for (const auto& circle : circles) {
            Point center(cvRound(circle[0]), cvRound(circle[1]));
            int radius = cvRound(circle[2]);
            std::cout << radius << std::endl;
            cv::circle(frame, center, radius, Scalar(0, 0, 255), 3, cv::LINE_AA);
        } */


    for( size_t i = 0; i < circles.size(); i++ )
    {
        Vec3i c = circles[i];
        Point center = Point(c[0], c[1]);
        // circle center
        circle( frame, center, 1, Scalar(0,100,100), 3, LINE_AA);
        // circle outline
        int radius = c[2];
        cv::circle(frame, center, radius, cv::Scalar(255, 0, 255), 3, cv::LINE_AA);
    }
/*         for (size_t i = 0; i < circles.size(); i++) {
            std::cout << "circle detect" << std::endl;
            cv::Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
            int radius = cvRound(circles[i][2]);
            cv::circle(frame, center, radius, cv::Scalar(0, 0, 255), 3, cv::LINE_AA);
} */

        // Display the frame
        imshow("Video", frame);

        // Wait for a key press
        if (waitKey(25) >= 0)
            break;
    }

    // Release the video file and destroy the window
    cap.release();
    destroyAllWindows();

    return 0;
}
