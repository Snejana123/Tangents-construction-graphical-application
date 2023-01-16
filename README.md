# Tangents-construction-graphical-application
Tangents construction graphical application for forming a segment drawn from an arbitrarily located point on a plane to a given circle.
Basic theoretical provisions.

![circle2](https://user-images.githubusercontent.com/103432419/212697201-a13aa44b-0818-4d94-9de6-197cee136803.png)

Let's construct a circle with the center O1 in the middle of the segment AO. Let's compose the equation of circles taking into account the transfer of the center O to the origin.

![formules](https://user-images.githubusercontent.com/103432419/212696639-8291403a-2b47-4285-8722-11a6ea917979.jpg)

a,b are O1 coordinates.
Let's find the intersection points of the circles - subtract the first from the second equation and express y, substitute the result into the second equation.

![formules_2](https://user-images.githubusercontent.com/103432419/212697584-b13de1a5-8ec1-4865-8957-f25473081053.jpg)

The roots of the quadratic equation are found in the algorithm itself using the discriminant. After that, all elements are shifted to the initial coordinates of the center O using the shift matrix.

Description of the interface.
The interface is a window application with a menu and a toolbar, a drawing, fields for entering values, a button for changing values, and a field with the exact coordinates of touch points to a given circle. Implemented txt file import and png export, with which it is possible to save previous drawings and track changes. The imported txt file must contain dotted decimal numbers in the given order: x-coordinate of the point, y-coordinate of the point, x-coordinate of the circle, y-coordinate of the circle, radius of the circle.
Fixed errors when entering data using regular expressions.
The application also implements console functions and importing files through the console, which can only be performed with executable files.

Screenshots illustrating the operation of the program.
Coordinate calculation and rendering

![2_1](https://user-images.githubusercontent.com/103432419/212704096-a04095cc-9eca-4c86-8bdf-61ce3813317a.png)

Export

![2_2](https://user-images.githubusercontent.com/103432419/212704213-0dda61fa-aa67-4457-b5df-376032280666.png)



![2_3](https://user-images.githubusercontent.com/103432419/212704697-ec639deb-996c-4d0e-8c22-41fa7a25a9e1.png)

Error output of unspecified file address

![2_4](https://user-images.githubusercontent.com/103432419/212704938-bce8391d-f8fc-4f1d-a951-eddd162deb10.png)

Output of missing data error for file export

![2_5](https://user-images.githubusercontent.com/103432419/212705165-71743c67-9943-43d5-8162-c1712ec84022.png)

File import

![2_6](https://user-images.githubusercontent.com/103432419/212705380-e62d2220-1d1b-4c6a-b145-52e6ae920300.png)

![2_7](https://user-images.githubusercontent.com/103432419/212705501-11d8c845-988b-4372-acbe-a9af1c3a31c3.png)

![2_8](https://user-images.githubusercontent.com/103432419/212705599-1163ae6f-4c38-4059-8f0b-5b7ec519697b.png)

Incorrect data

![изображение](https://user-images.githubusercontent.com/103432419/212706033-130dd795-164f-4a45-bfce-4430ec753169.png)







