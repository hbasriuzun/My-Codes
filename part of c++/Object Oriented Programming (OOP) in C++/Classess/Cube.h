#pragma once
namespace basri
{
        class Cube
    {
    private:
        double length_;

    public:
        double getVolume();
        double getSurfaceArea();
        void setLength(double lenght);
        double getLength();

    };
} 


