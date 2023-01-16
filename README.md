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

![изображение](https://user-images.githubusercontent.com/103432419/212706710-cee8405e-521d-4c4c-9e5d-ab327185975d.png)

Export

![изображение](https://user-images.githubusercontent.com/103432419/212706824-4f079181-6c44-404e-8e3f-20a2329b315b.png)

![изображение](https://user-images.githubusercontent.com/103432419/212707716-144d4d83-469c-4030-93c1-4df2e9343904.png)

Error output of unspecified file address

![изображение](https://user-images.githubusercontent.com/103432419/212707843-046fa6b7-f5d8-4fe0-9039-eaece22a3baf.png)

Output of missing data error for file export

![изображение](https://user-images.githubusercontent.com/103432419/212708061-26963537-ccc5-4745-a91c-5142779541f9.png)

File import

![изображение](https://user-images.githubusercontent.com/103432419/212708129-1ed4479e-6a83-4841-824c-2b6a16630707.png)

![изображение](https://user-images.githubusercontent.com/103432419/212708736-9531bf40-b3a7-4536-a135-688d9dead3a8.png)

![изображение](https://user-images.githubusercontent.com/103432419/212708819-0a461acd-f336-432c-ab6f-75ac5bfb7489.png)

Incorrect data

![изображение](https://user-images.githubusercontent.com/103432419/212706033-130dd795-164f-4a45-bfce-4430ec753169.png)








