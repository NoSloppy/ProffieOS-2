OUTPUT ?= $(wildcard *.png)

ALL: FCimage.h SCimage.h preview.png

# Full-Color images
FCimage.h: pnmtorle pnmwindshieldwiper *.png
	pngtopnm *.png | ./pnmwindshieldwiper | pnmscale -height $(HEIGHT) | ./pnmtorle > ../styles/$(basename $(OUTPUT))_$(HEIGHT)_FC_POV_data.h

#Single-Color images
SCimage.h: pgmtorle pnmwindshieldwiper *.png
	pngtopnm *.png | ./pnmwindshieldwiper| pnmscale -height $(HEIGHT) | ./pgmtorle > ../styles/$(basename $(OUTPUT))_$(HEIGHT)_SC_POV_data.h

preview.png: pnmwindshieldwiper *.png
	pngtopnm *.png | ./pnmwindshieldwiper| pnmscale -height $(HEIGHT) | pnmtopng > $(basename $(OUTPUT))_$(HEIGHT)_preview.png

pnmtorle: pnmtorle.cc
	g++ -O2 pnmtorle.cc -o pnmtorle -lm

pgmtorle: pgmtorle.cc
	g++ -O2 pgmtorle.cc -o pgmtorle -lm

pnmwindshieldwiper: pnmwindshieldwiper.cc
	g++ -O2 pnmwindshieldwiper.cc -o pnmwindshieldwiper -lm
