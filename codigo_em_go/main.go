package main

type Elemento struct {
	proximo *Elemento
	cliente Cliente
}
type Cliente struct {
	cod  int
	nome string
}
type TabelaHash struct {
	tamanho   int
	elementos []Elemento
}

func NewTabelaHash(tamanho int) TabelaHash {
	elementos := make([]Elemento, tamanho)
	return TabelaHash{
		tamanho:   tamanho,
		elementos: elementos,
	}
}

func (t TabelaHash) FuncaoHash(clienteCod int) int {
	result := clienteCod % t.tamanho
	return result
}

func (t TabelaHash) InsereClienteNaTabelaHash(cliente Cliente) int {
	result := t.FuncaoHash(cliente.cod)
	el := &t.elementos[result]
	for {
		if (*el).proximo == nil {
			(*el).proximo = &Elemento{
				proximo: nil,
				cliente: cliente,
			}
			break
		} else {
			el = (*el).proximo
		}
	}
	return 0
}

func main() {
	cliente1 := Cliente{
		cod:  49,
		nome: "Joao",
	}
	cliente2 := Cliente{
		cod:  49,
		nome: "Maria",
	}
	cliente3 := Cliente{
		cod:  49,
		nome: "Rodrigo",
	}
	tamanho := 7
	tabela := NewTabelaHash(tamanho)

	tabela.InsereClienteNaTabelaHash(cliente1)
	tabela.InsereClienteNaTabelaHash(cliente2)
	tabela.InsereClienteNaTabelaHash(cliente3)
}
