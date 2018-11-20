Resultados_hw4.pdf:Abiertas.png Normales.png Periodicas.png Resultados_hw4.tex
	pdflatex Resultados_hw4.tex
Abiertas.png:condicionesI.txt Abiertofinal.txt AbiertoInt2.txt AbiertolInt1.txt plot.py
	python plot.py
Normales.png:condicionesI.txt Normalfinal.txt NormalInt2.txt NormalInt1.txt plot.py
	python plot.py
Periodicas.png:condicionesI.txt Periodicofinal.txt PeriodicoInt2.txt PeridicolInt1.txt plot.py
	python plot.py
45.png:45.txt plot.py
	python plot.py
45.txt:ODE.cpp
	g++ -o datosangulos ODE.cpp
	./datosangulos
PeridicolInt1.txt:PDE.cpp
	g++ -o datos_x PDE.cpp
	./datos_x
PeriodicoInt2.txt:PDE.cpp
	g++ -o datos_x PDE.cpp
	./datos_x
Periodicofinal.txt:PDE.cpp
	g++ -o datos_x PDE.cpp
	./datos_x
Abiertofinal.txt:PDE.cpp
	g++ -o datos_x PDE.cpp
	./datos_x
AbiertoInt2.txt:PDE.cpp
	g++ -o datos_x PDE.cpp
	./datos_x
AbiertolInt1.txt:PDE.cpp
	g++ -o datos_x PDE.cpp
	./datos_x
Normalfinal.txt:PDE.cpp
	g++ -o datos_x PDE.cpp
	./datos_x
NormalInt2.txt:PDE.cpp
	g++ -o datos_x PDE.cpp
	./datos_x
NormalInt1.txt:PDE.cpp
	g++ -o datos_x PDE.cpp
	./datos_x
condicionesI.txt:PDE.cpp
	g++ -o datos_x PDE.cpp
	./datos_x
clean:
	rm *.txt
	rm *.png








