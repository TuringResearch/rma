package br.pro.turing.masiot.applicationlayer;

import br.pro.turing.masiot.core.model.Action;
import br.pro.turing.masiot.core.model.Command;
import br.pro.turing.masiot.core.model.ConnectionState;
import br.pro.turing.masiot.core.utils.LoggerUtils;
import lac.cnclib.net.NodeConnection;
import lac.cnclib.net.NodeConnectionListener;
import lac.cnclib.net.mrudp.MrUdpNodeConnection;
import lac.cnclib.sddl.message.ApplicationMessage;
import lac.cnclib.sddl.message.Message;
import lac.cnclib.sddl.serialization.Serialization;

import java.io.IOException;
import java.net.InetSocketAddress;
import java.net.SocketAddress;
import java.time.LocalDateTime;
import java.util.List;
import java.util.logging.Logger;

public class RMLBridge implements NodeConnectionListener {

    private static final Logger LOGGER = LoggerUtils.initLogger(RMLBridge.class.getClassLoader().getResourceAsStream(
            "br/pro/turing/masiot/applicationlayer/applicationlayer.logging.properties"), RMLBridge.class.getSimpleName());

    private MrUdpNodeConnection connection;

    private InetSocketAddress gatewayAddress;

    private ConnectionState connectionState = ConnectionState.OFFLINE;

    public void connect(String gatewayIP, int gatewayPort) {
        LOGGER.info("Connecting this client to RML.");
        this.gatewayAddress = new InetSocketAddress(gatewayIP, gatewayPort);
        try {
            connection = new MrUdpNodeConnection();
            connection.addNodeConnectionListener(this);
            connection.connect(gatewayAddress);
        } catch (IOException e) {
            LOGGER.severe("I/O exception error while try to connect this client to RML.");
        }
    }

    private void createAction(LocalDateTime localDateTime, Command command) {
        Action action = new Action(localDateTime, command.get_id());
        ApplicationMessage message = new ApplicationMessage();
        message.setContentObject(action);

        try {
            connection.sendMessage(message);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    @Override
    public void newMessageReceived(NodeConnection nodeConnection, Message message) {

    }

    @Override
    public void connected(NodeConnection nodeConnection) {
        LOGGER.info("Client connected.");
        this.connectionState = ConnectionState.ONLINE;
    }

    @Override
    public void reconnected(NodeConnection nodeConnection, SocketAddress socketAddress, boolean b, boolean b1) {
        LOGGER.info("Client reconnected.");
        this.connectionState = ConnectionState.ONLINE;
    }

    @Override
    public void disconnected(NodeConnection nodeConnection) {
        LOGGER.info("Client disconnected.");
        this.connectionState = ConnectionState.OFFLINE;
    }

    @Override
    public void unsentMessages(NodeConnection nodeConnection, List<Message> list) {
        StringBuilder errorMessageLog = new StringBuilder();
        errorMessageLog.append("Unsent mesage(s):");
        list.forEach(message -> errorMessageLog.append("\n")
                .append(Serialization.fromJavaByteStream(message.getContent()).toString()));
        LOGGER.severe(errorMessageLog.toString());
        if (this.connectionState.equals(ConnectionState.ONLINE)) {
            LOGGER.info("Resending messages");
            for (Message message : list) {
                try {
                    connection.sendMessage(message);
                } catch (IOException e) {
                    LOGGER.severe("I/O error while trying to send a message when this client connects with RML");
                    return;
                }
            }
        }
    }

    @Override
    public void internalException(NodeConnection nodeConnection, Exception e) {

    }
}
