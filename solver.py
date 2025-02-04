
def leer_archivo(archivo):
    laberinto=open(archivo,"r")
    filas = laberinto.readlines()
    laberinto.close()
    return filas

def alcanza_objetivo(filas_laberinto):
    llego_meta= False
    imposible=False
    i=0
    j=0
    camino=[]
    while not llego_meta and filas_laberinto[j-1][i] !="\n" and not imposible:
        j=0
        camino=[]
        while j != len(filas_laberinto) and filas_laberinto[j][i]!="1":
            camino.append((j+1,i+1))
            if filas_laberinto[j][i] == "X":
                llego_meta=True
            j+=1
        if filas_laberinto[1][i+1]=="1":
            imposible= True
        i+=1
    return llego_meta,camino       
        
    

if __name__ == "__main__":
    filas= leer_archivo(r"d:\Usuario\Escritorio\Workspace\C\prog2\laberinto.txt")
    print(alcanza_objetivo(filas))
    