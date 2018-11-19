#Make file S9C2

resultados.pdf:resultados.tex plot.pdf plot1.pdf
	pdflatex resultados.tex
plot.pdf:datos.dat plotdatos.py
	python plotdatos.py
datos.dat:makedatos.py
	python makedatos.py>>datos.dat

plot1.pdf:datos1.dat plotdatos1.py
	python plotdatos1.py
datos1.dat:a.out
	./a.out>>datos1.dat
a.out:makedatos1.cpp
	g++ makedatos1.cpp



#Make file Lab


display:sin.png
        display sin.png
sin.png:sin.txt plotea.py
        python plotea.py sin.txt
sin.txt:funcion.cpp output.txt
        g++ -o sin_x funcion.cpp
        ./sin_x






45.txt:PDE.cpp
        g++ -o datosangulos datos.cpp
        ./datosangulos



PeridicolInt1.txt:PDE.cpp
        g++ -o datos_x datos.cpp
        ./datos_x
PeriodicoInt2.txt:PDE.cpp
        g++ -o datos_x datos.cpp
        ./datos_x
Periodicofinal.txt:PDE.cpp
        g++ -o datos_x datos.cpp
        ./datos_x


Abiertofinal.txt:PDE.cpp
        g++ -o datos_x datos.cpp
        ./datos_x
AbiertoInt2.txt:PDE.cpp
        g++ -o datos_x datos.cpp
        ./datos_x
AbiertolInt1.txt:PDE.cpp
        g++ -o datos_x datos.cpp
        ./datos_x
Normalfinal.txt:PDE.cpp
        g++ -o datos_x datos.cpp
        ./datos_x
NormalInt2.txt:PDE.cpp
        g++ -o datos_x datos.cpp
        ./datos_x
NormalInt1.txt:PDE.cpp
        g++ -o datos_x datos.cpp
        ./datos_x
condicionesI.txt:PDE.cpp
        g++ -o datos_x datos.cpp
        ./datos_x
clean:
        rm *.txt
        rm *.png








