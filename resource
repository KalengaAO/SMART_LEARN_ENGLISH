Logo que definimos que o o modulos, armazenamos todos os topicos existemes em um vector e para 
cada pagina nova usamos std::vector::iterator< para acessar cada pagina que pertence ao mesmo 
modulo.

No interios da Gtk::Box text vamos adicionar o botão next, para indicar a proxima pagina.

Temos dois modo de abertura por numeração e por sequencia.

lógica do grid - modulos:

primeiro escolher o numero de pagina e depois o modulos.
usar o metodo join_dir;

Se não escolher o numero de pagina por padrão abra a primeira pagina.
