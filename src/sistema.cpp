


//FUNCION 2 SUELTA. INCLUIR CONTEXTO
void agregarVideojuego(string nombre, TipoJuego genero){
    Videojuego * v = new Videojuego(nombre,genero);
    videojuegos.next(v); //En la implementacion de lista debe lanzarse std::invalid_arg si el mismo ya existe...
}
