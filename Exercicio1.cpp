


class Biblioteca {
public:
    static void adicionarLivro(const string &titulo, const string &autor, int numCopias) {
        livros.push_back(Livro(titulo, autor, numCopias));
    }

    static bool verificarDisponibilidade(const string &titulo) {
        for(const auto &livro : livros) {
            if(livro.getTitulo() == titulo && livro.getNumCopias() > 0) {
                return true;
            }
        }
        return false;
    }

    static void listarLivrosEmprestados(const Usuario &usuario) {
        auto emprestimos = usuario.getEmprestimos();
        for(const auto &emprestimo : emprestimos) {
            cout << emprestimo.getLivro()->getTitulo() << " - " << emprestimo.getLivro()->getAutor() 
                 << " (Data do Emprestimo: " << emprestimo.getData() << ")" << endl;
        }
    }

    static vector<Livro>& getLivros() { return livros; }

private:
    static vector<Livro> livros;  
};

vector<Livro> Biblioteca::livros;


