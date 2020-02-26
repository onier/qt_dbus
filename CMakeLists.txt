cmake_minimum_required(VERSION 3.5)

project(DBusTest)

find_package(Qt5 CONFIG REQUIRED Core DBus)

set(prog_SRCS my.test.Calculator.xml)
qt5_generate_dbus_interface(Calc.hh
        my.test.Calculator.xml
        OPTIONS -A
        )
qt5_add_dbus_adaptor(prog_SRCS
        ${CMAKE_CURRENT_BINARY_DIR}/my.test.Calculator.xml
        Calc.hh
        Calc
        )

qt5_wrap_cpp(server_moc Calc.hh)
add_executable(QtDbusServer
        ${server_moc}
        server.cc
        Calc.cc
        ${prog_SRCS}
        )
target_include_directories(QtDbusServer
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_BINARY_DIR}
        )
target_link_libraries(QtDbusServer
        Qt5::DBus
        )

add_executable(QtDBusClient
        client.cc
        )
target_link_libraries(QtDBusClient
        Qt5::DBus
        )

qt5_wrap_cpp(listener_moc Listen.hh)
add_executable(QtDBusListener
        ${listener_moc}
        listener.cc
        Listen.cc
        )
target_link_libraries(QtDBusListener
        Qt5::DBus
        )