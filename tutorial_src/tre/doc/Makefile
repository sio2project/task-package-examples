#
# Makefile for LaTeX documents.
#
TEX  = $(wildcard [a-z]*.tex)
PDF  = $(patsubst %.tex,%.pdf,$(TEX))

all:  pdf

pdf: $(PDF)

%.pdf: %.tex
	pdflatex $*.tex
	pdflatex $*.tex

# You should use this option if you want to upload package.
clean:
	rm -f *~
	rm -f *.log
	rm -f *.aux
	rm -f *.dvi
	rm -f *.err
	rm -f *.inf

no_binaries: clean
	rm -f *.pdf
	rm -rf tmp
	rm -f *.css
	rm -f *.png
	rm -f *.html
