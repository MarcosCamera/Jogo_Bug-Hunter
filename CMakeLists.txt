# Versão mínima do CMake necessária
cmake_minimum_required(VERSION 3.10)

# Define o nome do projeto
project(jogo_simao VERSION 1.0)

# Define o padrão C++ a ser usado (ex: C++17)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --- Encontra a biblioteca SFML ---
# Esta é a "mágica" do CMake. Ele procura pelo SFML no sistema.
find_package(SFML 2.6 COMPONENTS graphics window system REQUIRED)

# Pega todos os nossos arquivos de código-fonte da pasta src e subpastas
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Adiciona o executável, que será criado a partir dos nossos arquivos-fonte
add_executable(jogo ${SOURCES})

# --- Linka o nosso executável com as bibliotecas do SFML ---
# Diz ao nosso alvo "jogo" para usar as bibliotecas que o find_package encontrou
target_link_libraries(jogo PRIVATE sfml-graphics sfml-window sfml-system GL X11 Xrandr Xcursor udev)

# Define o diretório de saída para os executáveis (opcional, mas organizado)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
