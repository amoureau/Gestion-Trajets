CC = g++
CFLAGS = -Wall -ansi -pedantic -std=c++11 -DMAP

# Liste des fichiers source
SRCS = main.cpp Trajet.cpp TrajetSimple.cpp TrajetCompose.cpp ElemListe.cpp ListeChainee.cpp Catalogue.cpp

# Dossier pour les fichiers objets
OBJ_DIR = objets

# Liste des fichiers objets générés à partir des fichiers source
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.cpp=.o))

# Nom de l'exécutable final
EXEC = trajets

# Règle par défaut pour construire l'exécutable
all: $(EXEC)

# Règle pour construire l'exécutable
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(EXEC)

# Règle générique pour générer les fichiers objets
$(OBJ_DIR)/%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Règle pour nettoyer les fichiers objets et l'exécutable
clean:
	rm -f $(OBJS) $(EXEC)

