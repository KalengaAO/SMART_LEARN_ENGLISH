Logo que definimos que o o modulos, armazenamos todos os topicos existemes em um vector e para 
cada pagina nova usamos std::vector::iterator< para acessar cada pagina que pertence ao mesmo 
modulo.

No interios da Gtk::Box text vamos adicionar o botão next, para indicar a proxima pagina.

Temos dois modo de abertura por numeração e por sequencia.

lógica do grid - modulos:

primeiro escolher o numero de pagina e depois o modulos.
usar o metodo join_dir;

Se não escolher o numero de pagina por padrão abra a primeira pagina.


HISTORY
o history será armazenado em um vector history;
Usa a memoria heap será melhor para não perdemos a referencia


precisar ler o ficheiro a cada eventos:: ERROR

export OPENROUTER_API_KEY="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"

