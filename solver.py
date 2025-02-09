def leer_archivo():
    archivo=input("Ingrese el nombre o ruta del archivo: ");
    laberinto=open(archivo,"r")
    filas=laberinto.readlines()
    laberinto.close()
    return filas

def alcanza_objetivo(filas):
    i=0
    j=0
    camino=[]
    llego_meta=False
    imposible= False
    while not llego_meta and not imposible and filas[j-1][i]!="\n":
        j=0
        while j!= len(filas) and filas[j][i]!="1":
            camino.append((j+1,i+1))
            if filas[j][i]=="X":
                llego_meta=True
            j+=1
        if filas[0][i+1]=="1":
            imposible=True
        i+=1
    if not llego_meta:
        camino.clear()
    
    return llego_meta,camino

if __name__=="__main__":
    filas_laberinto=leer_archivo()
    solver=alcanza_objetivo(filas_laberinto)
    print(solver)
    
