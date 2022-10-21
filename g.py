import matplotlib.pyplot as plt
import math
import numpy as np
import fileinput as fl


pizzachili=["dblp.xml.10MB",  "dna.10MB",  "english.10MB",  "pitches.10MB",  "proteins.10MB",  "sources.10MB"]
calgary=["bib",  "book1",  "book2",  "geo",  "news",  "obj1",  "obj2",  "paper1",  "paper2",  "progc",  "progl",  "progp",  "trans"]
i=1;
for t in pizzachili:
    plt.subplot(2,3,i)
    p=1
    for line in fl.input(files="ans/"+t):
        l=line.split()
        if len(l) == 1:
            p=int(l[0])
        else:
            plt.plot(1/float(l[1]),int(l[0])/p,'bo')
    x=[0,1000]
    y=[1,1]
    plt.plot(x,y)
    plt.title(t)
    plt.xscale("log")
    i=i+1
plt.subplots_adjust(top=0.92, bottom=0.08, left=0.10, right=0.95, hspace=0.25,
                    wspace=0.35)
plt.show()
