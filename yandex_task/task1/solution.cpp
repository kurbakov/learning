#include <stdio.h>
#include <iostream>

class Feature
{
public:

    // ================================
    //      public variables
    // ================================
    enum FeatureType {eUnknown, eCircle, eTriangle, eSquare};

    // ===============================
    //      constructor / destructor
    // ================================
    Feature()
    {
        type = eUnknown;

        // changed from points(0) to new double;
        // reason: different data types!
        points = new double;
    }

    ~Feature()
    {
        if (points)
        {
            // added points = NULL before deleting
            // to exclude memory problem (blocking)
            points = NULL;
            delete points;
        }
    }

    // ================================
    //      public functions
    // ================================
    bool isValid()
    {
        // in case they are not the same => true,
        // else => false
        return type != eUnknown;
    }

    bool read(FILE* file)
    {
        // check wheather the read was successful
        if(fread(&type, sizeof(FeatureType), 1, file) != 1)
        {
            return false;
        }

        short n;
        switch (type)
        {
            case eCircle: n = 3; break;
            case eTriangle: n = 6; break;
            case eSquare: n = 8; break;
            default: type = eUnknown; return false;
        }

        points = new double[n];

        // check weather the reading operation was successful
        if(fread(&points, sizeof(double), n, file) != 1)
        {
            return false;
        }

        // compare 2 sizeof(); real vs expected!
        return sizeof(&points) == n*sizeof(double);
    }

    void draw()
    {
        switch (type)
        {
            // we do not cover all cases, because in main function
            // we check if (!feature.isValid()) before run draw()
            // so the case type == eUnknown is excluded

            case eCircle: drawCircle(points, 3); break;
            case eTriangle: drawPolygon(points, 6); break;
            case eSquare: drawPolygon(points, 8); break;
        }
    }


protected:

    // ================================
    //      protected variables
    // ================================
    double* points;
    FeatureType type;

    // ================================
    //      protected functions
    // ================================

    // functions defined but not implemented.
    // basically the class knows that the functions exist but
    // has no idea what they do.

    // we need to write this functions
    // based om the framework we can do. visualization is not
    // in the standard library in c++
    void drawCircle(double* points, int size)
    {
        // TODO based on the framework

    }
    void drawPolygon(double* points, int size)
    {
        // TODO based on the framework
        if (size == 6)
        {
            // draw triangle
        }
        else if (size == 8)
        {
            // draw square
        }

    }

};

int main(int argc, char* argv[])
{

    FILE* file = fopen("features.dat", "r");

    // if file is not found
    // exit(1)
    if (file == NULL)
    {
        std::cout << "the file was not found!" << std::endl;
        exit(1);
    }

    Feature feature;
    feature.read(file);

    // when we are done with the file
    // close the connection
    fclose(file);

    if (!feature.isValid())
    {
        return 1;
    }

    // call the function draw()
    // and destructor in the end of the function
    feature.draw();
    feature.~Feature();

    return 0;
}
