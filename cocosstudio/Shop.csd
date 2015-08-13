<GameProjectFile>
  <PropertyGroup Type="Layer" Name="Shop" ID="7ebcafc8-b3fc-44e0-a212-d639e3e6db5b" Version="2.3.1.2" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="0" Speed="1.0000" />
      <ObjectData Name="Layer" CustomClassName="Shop" Tag="114" ctype="GameLayerObjectData">
        <Size X="1136.0000" Y="640.0000" />
        <Children>
          <AbstractNodeData Name="menu" ActionTag="-1252097155" Tag="150" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="68.0000" RightMargin="68.0000" TopMargin="8.5001" BottomMargin="30.4999" ctype="SpriteObjectData">
            <Size X="1000.0000" Y="601.0000" />
            <Children>
              <AbstractNodeData Name="lineup" ActionTag="-779193947" Tag="67" IconVisible="False" LeftMargin="199.3994" RightMargin="408.6006" TopMargin="142.1086" BottomMargin="373.8914" LabelText="ラインナップ" ctype="TextBMFontObjectData">
                <Size X="392.0000" Y="85.0000" />
                <AnchorPoint ScaleY="0.5000" />
                <Position X="199.3994" Y="416.3914" />
                <Scale ScaleX="0.5000" ScaleY="0.5000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.1994" Y="0.6928" />
                <PreSize X="0.3920" Y="0.1414" />
                <LabelBMFontFile_CNB Type="Normal" Path="font/zoo_font3.fnt" Plist="" />
              </AbstractNodeData>
              <AbstractNodeData Name="line_1" ActionTag="-2112867300" Tag="66" IconVisible="False" LeftMargin="185.0182" RightMargin="178.9818" TopMargin="212.4418" BottomMargin="378.5582" ctype="SpriteObjectData">
                <Size X="636.0000" Y="10.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="503.0182" Y="383.5582" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5030" Y="0.6382" />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="Normal" Path="ui/line.png" Plist="" />
                <BlendFunc Src="1" Dst="771" />
              </AbstractNodeData>
              <AbstractNodeData Name="diamond_1" ActionTag="1178094178" Tag="219" IconVisible="False" PositionPercentYEnabled="True" LeftMargin="494.3787" RightMargin="333.6213" TopMargin="60.8475" BottomMargin="392.1525" ctype="SpriteObjectData">
                <Size X="172.0000" Y="148.0000" />
                <AnchorPoint ScaleX="0.5000" />
                <Position X="580.3787" Y="392.1525" />
                <Scale ScaleX="0.4000" ScaleY="0.4000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5804" Y="0.6525" />
                <PreSize X="0.1720" Y="0.2463" />
                <FileData Type="Normal" Path="ui/diamond.png" Plist="" />
                <BlendFunc Src="1" Dst="771" />
              </AbstractNodeData>
              <AbstractNodeData Name="hasDiamondNum" ActionTag="-1200641410" Tag="220" IconVisible="False" PositionPercentYEnabled="True" LeftMargin="583.6619" RightMargin="220.3381" TopMargin="126.2849" BottomMargin="393.7151" LabelText="x 0000" ctype="TextBMFontObjectData">
                <Size X="196.0000" Y="81.0000" />
                <AnchorPoint ScaleX="1.0000" />
                <Position X="779.6619" Y="393.7151" />
                <Scale ScaleX="0.8000" ScaleY="0.8000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.7797" Y="0.6551" />
                <PreSize X="0.1960" Y="0.1348" />
                <LabelBMFontFile_CNB Type="Normal" Path="font/zoo_font2.fnt" Plist="" />
              </AbstractNodeData>
              <AbstractNodeData Name="title" ActionTag="-420158703" Tag="151" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="370.0000" RightMargin="370.0000" TopMargin="44.4213" BottomMargin="475.5787" LabelText="ショップ" ctype="TextBMFontObjectData">
                <Size X="260.0000" Y="81.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="500.0000" Y="516.0787" />
                <Scale ScaleX="0.6000" ScaleY="0.7000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5000" Y="0.8587" />
                <PreSize X="0.2600" Y="0.1348" />
                <LabelBMFontFile_CNB Type="Normal" Path="font/zoo_font2.fnt" Plist="" />
              </AbstractNodeData>
              <AbstractNodeData Name="offenseUp" ActionTag="528517738" Tag="152" IconVisible="True" PositionPercentYEnabled="True" LeftMargin="219.4581" RightMargin="780.5419" TopMargin="250.4968" BottomMargin="350.5032" ctype="SingleNodeObjectData">
                <Size X="0.0000" Y="0.0000" />
                <Children>
                  <AbstractNodeData Name="button" ActionTag="2108392878" Tag="153" IconVisible="False" LeftMargin="492.9978" RightMargin="-790.9978" TopMargin="-50.0000" BottomMargin="-50.0000" TouchEnable="True" FontSize="14" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="268" Scale9Height="78" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                    <Size X="298.0000" Y="100.0000" />
                    <Children>
                      <AbstractNodeData Name="diamond" ActionTag="-466018773" Tag="154" IconVisible="False" PositionPercentYEnabled="True" LeftMargin="-4.6726" RightMargin="130.6726" TopMargin="-24.0000" BottomMargin="-24.0000" ctype="SpriteObjectData">
                        <Size X="172.0000" Y="148.0000" />
                        <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                        <Position X="81.3274" Y="50.0000" />
                        <Scale ScaleX="0.4500" ScaleY="0.4500" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.2729" Y="0.5000" />
                        <PreSize X="0.5772" Y="1.4800" />
                        <FileData Type="Normal" Path="ui/diamond.png" Plist="" />
                        <BlendFunc Src="1" Dst="771" />
                      </AbstractNodeData>
                      <AbstractNodeData Name="requreNum" ActionTag="-705016769" Tag="155" IconVisible="False" PositionPercentYEnabled="True" LeftMargin="129.6968" RightMargin="36.3032" TopMargin="9.5000" BottomMargin="9.5000" LabelText="x 10" ctype="TextBMFontObjectData">
                        <Size X="132.0000" Y="81.0000" />
                        <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                        <Position X="195.6968" Y="50.0000" />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.6567" Y="0.5000" />
                        <PreSize X="0.4430" Y="0.8100" />
                        <LabelBMFontFile_CNB Type="Normal" Path="font/zoo_font2.fnt" Plist="" />
                      </AbstractNodeData>
                    </Children>
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="641.9978" />
                    <Scale ScaleX="0.5000" ScaleY="0.5000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                    <TextColor A="255" R="65" G="65" B="70" />
                    <DisabledFileData Type="Normal" Path="ui/button03_disable.png" Plist="" />
                    <PressedFileData Type="Normal" Path="ui/button03.png" Plist="" />
                    <NormalFileData Type="Normal" Path="ui/button03.png" Plist="" />
                    <OutlineColor A="255" R="255" G="0" B="0" />
                    <ShadowColor A="255" R="110" G="110" B="110" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="nextValue" ActionTag="472686781" Tag="156" IconVisible="False" PositionPercentYEnabled="True" LeftMargin="374.2579" RightMargin="-546.2579" TopMargin="-40.5000" BottomMargin="-40.5000" LabelText="1.5倍" ctype="TextBMFontObjectData">
                    <Size X="172.0000" Y="81.0000" />
                    <AnchorPoint ScaleX="1.0000" ScaleY="0.5000" />
                    <Position X="546.2579" />
                    <Scale ScaleX="0.5000" ScaleY="0.5000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                    <LabelBMFontFile_CNB Type="Normal" Path="font/zoo_font2.fnt" Plist="" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="description" ActionTag="-767279310" Tag="157" IconVisible="False" LeftMargin="0.0001" RightMargin="-257.0001" TopMargin="-17.5000" BottomMargin="-17.5000" LabelText="動物の攻撃力アップ" ctype="TextBMFontObjectData">
                    <Size X="257.0000" Y="35.0000" />
                    <AnchorPoint ScaleY="0.5000" />
                    <Position X="0.0001" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                    <LabelBMFontFile_CNB Type="Normal" Path="font/zoo_font5.fnt" Plist="" />
                  </AbstractNodeData>
                </Children>
                <AnchorPoint />
                <Position X="219.4581" Y="350.5032" />
                <Scale ScaleX="0.8000" ScaleY="0.8000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.2195" Y="0.5832" />
                <PreSize X="0.0000" Y="0.0000" />
              </AbstractNodeData>
              <AbstractNodeData Name="spawnNum" ActionTag="-70746800" Tag="158" IconVisible="True" PositionPercentYEnabled="True" LeftMargin="219.4581" RightMargin="780.5419" TopMargin="386.5482" BottomMargin="214.4518" ctype="SingleNodeObjectData">
                <Size X="0.0000" Y="0.0000" />
                <Children>
                  <AbstractNodeData Name="button" ActionTag="195251998" Tag="159" IconVisible="False" LeftMargin="492.2521" RightMargin="-790.2521" TopMargin="-50.0001" BottomMargin="-49.9999" TouchEnable="True" FontSize="14" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="268" Scale9Height="78" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                    <Size X="298.0000" Y="100.0000" />
                    <Children>
                      <AbstractNodeData Name="diamond" ActionTag="-1871963264" Tag="160" IconVisible="False" PositionPercentYEnabled="True" LeftMargin="-4.6726" RightMargin="130.6726" TopMargin="-24.0000" BottomMargin="-24.0000" ctype="SpriteObjectData">
                        <Size X="172.0000" Y="148.0000" />
                        <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                        <Position X="81.3274" Y="50.0000" />
                        <Scale ScaleX="0.4500" ScaleY="0.4500" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.2729" Y="0.5000" />
                        <PreSize X="0.5772" Y="1.4800" />
                        <FileData Type="Normal" Path="ui/diamond.png" Plist="" />
                        <BlendFunc Src="1" Dst="771" />
                      </AbstractNodeData>
                      <AbstractNodeData Name="requreNum" ActionTag="-1440329710" Tag="161" IconVisible="False" PositionPercentYEnabled="True" LeftMargin="129.6968" RightMargin="36.3032" TopMargin="9.5000" BottomMargin="9.5000" LabelText="x 10" ctype="TextBMFontObjectData">
                        <Size X="132.0000" Y="81.0000" />
                        <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                        <Position X="195.6968" Y="50.0000" />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.6567" Y="0.5000" />
                        <PreSize X="0.4430" Y="0.8100" />
                        <LabelBMFontFile_CNB Type="Normal" Path="font/zoo_font2.fnt" Plist="" />
                      </AbstractNodeData>
                    </Children>
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="641.2521" Y="0.0001" />
                    <Scale ScaleX="0.5000" ScaleY="0.5000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                    <TextColor A="255" R="65" G="65" B="70" />
                    <DisabledFileData Type="Normal" Path="ui/button03_disable.png" Plist="" />
                    <PressedFileData Type="Normal" Path="ui/button03.png" Plist="" />
                    <NormalFileData Type="Normal" Path="ui/button03.png" Plist="" />
                    <OutlineColor A="255" R="255" G="0" B="0" />
                    <ShadowColor A="255" R="110" G="110" B="110" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="nextValue" ActionTag="1413115161" Tag="162" IconVisible="False" PositionPercentYEnabled="True" LeftMargin="440.2568" RightMargin="-546.2568" TopMargin="-40.5000" BottomMargin="-40.5000" LabelText="2匹" ctype="TextBMFontObjectData">
                    <Size X="106.0000" Y="81.0000" />
                    <AnchorPoint ScaleX="1.0000" ScaleY="0.5000" />
                    <Position X="546.2568" />
                    <Scale ScaleX="0.5000" ScaleY="0.5000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                    <LabelBMFontFile_CNB Type="Normal" Path="font/zoo_font2.fnt" Plist="" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="description" ActionTag="651894491" Tag="163" IconVisible="False" LeftMargin="0.0001" RightMargin="-290.0001" TopMargin="-17.5000" BottomMargin="-17.5000" LabelText="ツボから出る動物の数アップ" ctype="TextBMFontObjectData">
                    <Size X="374.0000" Y="35.0000" />
                    <AnchorPoint ScaleY="0.5000" />
                    <Position X="0.0001" />
                    <Scale ScaleX="0.9000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                    <LabelBMFontFile_CNB Type="Normal" Path="font/zoo_font5.fnt" Plist="" />
                  </AbstractNodeData>
                </Children>
                <AnchorPoint />
                <Position X="219.4581" Y="214.4518" />
                <Scale ScaleX="0.8000" ScaleY="0.8000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.2195" Y="0.3568" />
                <PreSize X="0.0000" Y="0.0000" />
              </AbstractNodeData>
              <AbstractNodeData Name="animalNum" ActionTag="-475703228" Tag="164" IconVisible="True" PositionPercentYEnabled="True" LeftMargin="219.4581" RightMargin="780.5419" TopMargin="341.2178" BottomMargin="259.7822" ctype="SingleNodeObjectData">
                <Size X="0.0000" Y="0.0000" />
                <Children>
                  <AbstractNodeData Name="button" ActionTag="649164083" Tag="165" IconVisible="False" LeftMargin="492.2521" RightMargin="-790.2521" TopMargin="-49.9998" BottomMargin="-50.0002" TouchEnable="True" FontSize="14" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="268" Scale9Height="78" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                    <Size X="298.0000" Y="100.0000" />
                    <Children>
                      <AbstractNodeData Name="diamond" ActionTag="-1403824263" Tag="166" IconVisible="False" PositionPercentYEnabled="True" LeftMargin="-4.6726" RightMargin="130.6726" TopMargin="-24.0000" BottomMargin="-24.0000" ctype="SpriteObjectData">
                        <Size X="172.0000" Y="148.0000" />
                        <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                        <Position X="81.3274" Y="50.0000" />
                        <Scale ScaleX="0.4500" ScaleY="0.4500" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.2729" Y="0.5000" />
                        <PreSize X="0.5772" Y="1.4800" />
                        <FileData Type="Normal" Path="ui/diamond.png" Plist="" />
                        <BlendFunc Src="1" Dst="771" />
                      </AbstractNodeData>
                      <AbstractNodeData Name="requreNum" ActionTag="834987645" Tag="167" IconVisible="False" PositionPercentYEnabled="True" LeftMargin="129.6968" RightMargin="36.3032" TopMargin="9.5000" BottomMargin="9.5000" LabelText="x 10" ctype="TextBMFontObjectData">
                        <Size X="132.0000" Y="81.0000" />
                        <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                        <Position X="195.6968" Y="50.0000" />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.6567" Y="0.5000" />
                        <PreSize X="0.4430" Y="0.8100" />
                        <LabelBMFontFile_CNB Type="Normal" Path="font/zoo_font2.fnt" Plist="" />
                      </AbstractNodeData>
                    </Children>
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="641.2521" Y="-0.0002" />
                    <Scale ScaleX="0.5000" ScaleY="0.5000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                    <TextColor A="255" R="65" G="65" B="70" />
                    <DisabledFileData Type="Normal" Path="ui/button03_disable.png" Plist="" />
                    <PressedFileData Type="Normal" Path="ui/button03.png" Plist="" />
                    <NormalFileData Type="Normal" Path="ui/button03.png" Plist="" />
                    <OutlineColor A="255" R="255" G="0" B="0" />
                    <ShadowColor A="255" R="110" G="110" B="110" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="nextValue" ActionTag="7410351" Tag="168" IconVisible="False" PositionPercentYEnabled="True" LeftMargin="408.2570" RightMargin="-546.2570" TopMargin="-40.5000" BottomMargin="-40.5000" LabelText="21匹" ctype="TextBMFontObjectData">
                    <Size X="138.0000" Y="81.0000" />
                    <AnchorPoint ScaleX="1.0000" ScaleY="0.5000" />
                    <Position X="546.2570" />
                    <Scale ScaleX="0.5000" ScaleY="0.5000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                    <LabelBMFontFile_CNB Type="Normal" Path="font/zoo_font2.fnt" Plist="" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="description" ActionTag="-1193281071" Tag="169" IconVisible="False" PositionPercentYEnabled="True" LeftMargin="0.0000" RightMargin="-260.0000" TopMargin="-17.5000" BottomMargin="-17.5000" LabelText="保持できる動物の数アップ" ctype="TextBMFontObjectData">
                    <Size X="344.0000" Y="35.0000" />
                    <AnchorPoint ScaleY="0.5000" />
                    <Position X="0.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                    <LabelBMFontFile_CNB Type="Normal" Path="font/zoo_font5.fnt" Plist="" />
                  </AbstractNodeData>
                </Children>
                <AnchorPoint />
                <Position X="219.4581" Y="259.7822" />
                <Scale ScaleX="0.8000" ScaleY="0.8000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.2195" Y="0.4322" />
                <PreSize X="0.0000" Y="0.0000" />
              </AbstractNodeData>
              <AbstractNodeData Name="getCoin" ActionTag="870292953" Tag="170" IconVisible="True" PositionPercentYEnabled="True" LeftMargin="219.4581" RightMargin="780.5419" TopMargin="295.8874" BottomMargin="305.1126" ctype="SingleNodeObjectData">
                <Size X="0.0000" Y="0.0000" />
                <Children>
                  <AbstractNodeData Name="button" ActionTag="-1000277048" Tag="171" IconVisible="False" LeftMargin="492.2521" RightMargin="-790.2521" TopMargin="-50.0001" BottomMargin="-49.9999" TouchEnable="True" FontSize="14" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="268" Scale9Height="78" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                    <Size X="298.0000" Y="100.0000" />
                    <Children>
                      <AbstractNodeData Name="diamond" ActionTag="-855150752" Tag="172" IconVisible="False" PositionPercentYEnabled="True" LeftMargin="-4.6726" RightMargin="130.6726" TopMargin="-24.0000" BottomMargin="-24.0000" ctype="SpriteObjectData">
                        <Size X="172.0000" Y="148.0000" />
                        <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                        <Position X="81.3274" Y="50.0000" />
                        <Scale ScaleX="0.4500" ScaleY="0.4500" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.2729" Y="0.5000" />
                        <PreSize X="0.5772" Y="1.4800" />
                        <FileData Type="Normal" Path="ui/diamond.png" Plist="" />
                        <BlendFunc Src="1" Dst="771" />
                      </AbstractNodeData>
                      <AbstractNodeData Name="requreNum" ActionTag="-149824275" Tag="173" IconVisible="False" PositionPercentYEnabled="True" LeftMargin="129.6968" RightMargin="36.3032" TopMargin="9.5000" BottomMargin="9.5000" LabelText="x 10" ctype="TextBMFontObjectData">
                        <Size X="132.0000" Y="81.0000" />
                        <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                        <Position X="195.6968" Y="50.0000" />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.6567" Y="0.5000" />
                        <PreSize X="0.4430" Y="0.8100" />
                        <LabelBMFontFile_CNB Type="Normal" Path="font/zoo_font2.fnt" Plist="" />
                      </AbstractNodeData>
                    </Children>
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="641.2521" Y="0.0001" />
                    <Scale ScaleX="0.5000" ScaleY="0.5000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                    <TextColor A="255" R="65" G="65" B="70" />
                    <DisabledFileData Type="Normal" Path="ui/button03_disable.png" Plist="" />
                    <PressedFileData Type="Normal" Path="ui/button03.png" Plist="" />
                    <NormalFileData Type="Normal" Path="ui/button03.png" Plist="" />
                    <OutlineColor A="255" R="255" G="0" B="0" />
                    <ShadowColor A="255" R="110" G="110" B="110" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="nextValue" ActionTag="-305455982" Tag="174" IconVisible="False" LeftMargin="374.2578" RightMargin="-546.2578" TopMargin="-40.5001" BottomMargin="-40.4999" LabelText="1.5倍" ctype="TextBMFontObjectData">
                    <Size X="172.0000" Y="81.0000" />
                    <AnchorPoint ScaleX="1.0000" ScaleY="0.5000" />
                    <Position X="546.2578" Y="0.0001" />
                    <Scale ScaleX="0.5000" ScaleY="0.5000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                    <LabelBMFontFile_CNB Type="Normal" Path="font/zoo_font2.fnt" Plist="" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="description" ActionTag="-1578028345" Tag="175" IconVisible="False" RightMargin="-203.0000" TopMargin="-15.8864" BottomMargin="-19.1136" LabelText="コインの取得量アップ" ctype="TextBMFontObjectData">
                    <Size X="288.0000" Y="35.0000" />
                    <AnchorPoint ScaleY="0.5000" />
                    <Position Y="-1.6136" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                    <LabelBMFontFile_CNB Type="Normal" Path="font/zoo_font5.fnt" Plist="" />
                  </AbstractNodeData>
                </Children>
                <AnchorPoint />
                <Position X="219.4581" Y="305.1126" />
                <Scale ScaleX="0.8000" ScaleY="0.8000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.2195" Y="0.5077" />
                <PreSize X="0.0000" Y="0.0000" />
              </AbstractNodeData>
              <AbstractNodeData Name="emergeEnemy" ActionTag="2139147446" Tag="176" IconVisible="True" PositionPercentYEnabled="True" LeftMargin="219.4581" RightMargin="780.5419" TopMargin="429.9388" BottomMargin="171.0612" ctype="SingleNodeObjectData">
                <Size X="0.0000" Y="0.0000" />
                <Children>
                  <AbstractNodeData Name="button" ActionTag="-1232556359" Tag="177" IconVisible="False" LeftMargin="492.2521" RightMargin="-790.2521" TopMargin="-50.0000" BottomMargin="-50.0000" TouchEnable="True" FontSize="14" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="268" Scale9Height="78" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                    <Size X="298.0000" Y="100.0000" />
                    <Children>
                      <AbstractNodeData Name="diamond" ActionTag="320712365" Tag="178" IconVisible="False" PositionPercentYEnabled="True" LeftMargin="-4.6726" RightMargin="130.6726" TopMargin="-24.0000" BottomMargin="-24.0000" ctype="SpriteObjectData">
                        <Size X="172.0000" Y="148.0000" />
                        <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                        <Position X="81.3274" Y="50.0000" />
                        <Scale ScaleX="0.4500" ScaleY="0.4500" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.2729" Y="0.5000" />
                        <PreSize X="0.5772" Y="1.4800" />
                        <FileData Type="Normal" Path="ui/diamond.png" Plist="" />
                        <BlendFunc Src="1" Dst="771" />
                      </AbstractNodeData>
                      <AbstractNodeData Name="requreNum" ActionTag="-1807709403" Tag="179" IconVisible="False" PositionPercentYEnabled="True" LeftMargin="129.6968" RightMargin="36.3032" TopMargin="9.5000" BottomMargin="9.5000" LabelText="x 10" ctype="TextBMFontObjectData">
                        <Size X="132.0000" Y="81.0000" />
                        <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                        <Position X="195.6968" Y="50.0000" />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.6567" Y="0.5000" />
                        <PreSize X="0.4430" Y="0.8100" />
                        <LabelBMFontFile_CNB Type="Normal" Path="font/zoo_font2.fnt" Plist="" />
                      </AbstractNodeData>
                    </Children>
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="641.2521" />
                    <Scale ScaleX="0.5000" ScaleY="0.5000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                    <TextColor A="255" R="65" G="65" B="70" />
                    <DisabledFileData Type="Normal" Path="ui/button03_disable.png" Plist="" />
                    <PressedFileData Type="Normal" Path="ui/button03.png" Plist="" />
                    <NormalFileData Type="Normal" Path="ui/button03.png" Plist="" />
                    <OutlineColor A="255" R="255" G="0" B="0" />
                    <ShadowColor A="255" R="110" G="110" B="110" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="nextValue" ActionTag="-2121557404" Tag="180" IconVisible="False" PositionPercentYEnabled="True" LeftMargin="374.2578" RightMargin="-546.2578" TopMargin="-40.5000" BottomMargin="-40.5000" LabelText="1.5倍" ctype="TextBMFontObjectData">
                    <Size X="172.0000" Y="81.0000" />
                    <AnchorPoint ScaleX="1.0000" ScaleY="0.5000" />
                    <Position X="546.2578" />
                    <Scale ScaleX="0.5000" ScaleY="0.5000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                    <LabelBMFontFile_CNB Type="Normal" Path="font/zoo_font2.fnt" Plist="" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="description" ActionTag="1622353508" Tag="181" IconVisible="False" LeftMargin="0.0001" RightMargin="-203.0001" TopMargin="-17.5000" BottomMargin="-17.5000" LabelText="出現する敵の数アップ" ctype="TextBMFontObjectData">
                    <Size X="287.0000" Y="35.0000" />
                    <AnchorPoint ScaleY="0.5000" />
                    <Position X="0.0001" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                    <LabelBMFontFile_CNB Type="Normal" Path="font/zoo_font5.fnt" Plist="" />
                  </AbstractNodeData>
                </Children>
                <AnchorPoint />
                <Position X="219.4581" Y="171.0612" />
                <Scale ScaleX="0.8000" ScaleY="0.8000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.2195" Y="0.2846" />
                <PreSize X="0.0000" Y="0.0000" />
              </AbstractNodeData>
              <AbstractNodeData Name="okButton" ActionTag="-993402210" Tag="182" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="400.0000" RightMargin="400.0000" TopMargin="512.8732" BottomMargin="-31.8732" TouchEnable="True" FontSize="14" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="275" Scale9Height="112" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                <Size X="200.0000" Y="120.0000" />
                <Children>
                  <AbstractNodeData Name="coinLabel_0" ActionTag="199476714" Tag="183" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="45.0000" RightMargin="45.0000" TopMargin="19.5000" BottomMargin="19.5000" LabelText="OK" ctype="TextBMFontObjectData">
                    <Size X="110.0000" Y="81.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="100.0000" Y="60.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition X="0.5000" Y="0.5000" />
                    <PreSize X="0.5500" Y="0.6750" />
                    <LabelBMFontFile_CNB Type="Normal" Path="font/zoo_font2.fnt" Plist="" />
                  </AbstractNodeData>
                </Children>
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="500.0000" Y="28.1268" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5000" Y="0.0468" />
                <PreSize X="0.2000" Y="0.1997" />
                <TextColor A="255" R="65" G="65" B="70" />
                <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
                <PressedFileData Type="Normal" Path="ui/button02.png" Plist="" />
                <NormalFileData Type="Normal" Path="ui/button02.png" Plist="" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
              <AbstractNodeData Name="maxLife" ActionTag="-1653187990" Tag="64" IconVisible="True" PositionPercentYEnabled="True" LeftMargin="219.2194" RightMargin="780.7806" TopMargin="472.1176" BottomMargin="128.8824" ctype="SingleNodeObjectData">
                <Size X="0.0000" Y="0.0000" />
                <Children>
                  <AbstractNodeData Name="button" ActionTag="-1720649083" Tag="65" IconVisible="False" LeftMargin="492.2520" RightMargin="-790.2520" TopMargin="-50.0000" BottomMargin="-50.0000" TouchEnable="True" FontSize="14" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="268" Scale9Height="78" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                    <Size X="298.0000" Y="100.0000" />
                    <Children>
                      <AbstractNodeData Name="diamond" ActionTag="-454444690" Tag="66" IconVisible="False" PositionPercentYEnabled="True" LeftMargin="-4.6726" RightMargin="130.6726" TopMargin="-24.0000" BottomMargin="-24.0000" ctype="SpriteObjectData">
                        <Size X="172.0000" Y="148.0000" />
                        <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                        <Position X="81.3274" Y="50.0000" />
                        <Scale ScaleX="0.4500" ScaleY="0.4500" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.2729" Y="0.5000" />
                        <PreSize X="0.5772" Y="1.4800" />
                        <FileData Type="Normal" Path="ui/diamond.png" Plist="" />
                        <BlendFunc Src="1" Dst="771" />
                      </AbstractNodeData>
                      <AbstractNodeData Name="requreNum" ActionTag="1627235019" Tag="67" IconVisible="False" PositionPercentYEnabled="True" LeftMargin="129.6968" RightMargin="36.3032" TopMargin="9.5000" BottomMargin="9.5000" LabelText="x 10" ctype="TextBMFontObjectData">
                        <Size X="132.0000" Y="81.0000" />
                        <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                        <Position X="195.6968" Y="50.0000" />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.6567" Y="0.5000" />
                        <PreSize X="0.4430" Y="0.8100" />
                        <LabelBMFontFile_CNB Type="Normal" Path="font/zoo_font2.fnt" Plist="" />
                      </AbstractNodeData>
                    </Children>
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="641.2520" Y="0.0000" />
                    <Scale ScaleX="0.5000" ScaleY="0.5000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                    <TextColor A="255" R="65" G="65" B="70" />
                    <DisabledFileData Type="Normal" Path="ui/button03_disable.png" Plist="" />
                    <PressedFileData Type="Normal" Path="ui/button03.png" Plist="" />
                    <NormalFileData Type="Normal" Path="ui/button03.png" Plist="" />
                    <OutlineColor A="255" R="255" G="0" B="0" />
                    <ShadowColor A="255" R="110" G="110" B="110" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="nextValue" ActionTag="1084290808" Tag="68" IconVisible="False" PositionPercentYEnabled="True" LeftMargin="438.2582" RightMargin="-546.2582" TopMargin="-40.5000" BottomMargin="-40.5000" LabelText="3個" ctype="TextBMFontObjectData">
                    <Size X="108.0000" Y="81.0000" />
                    <AnchorPoint ScaleX="1.0000" ScaleY="0.5000" />
                    <Position X="546.2582" />
                    <Scale ScaleX="0.5000" ScaleY="0.5000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                    <LabelBMFontFile_CNB Type="Normal" Path="font/zoo_font2.fnt" Plist="" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="description" ActionTag="-87818536" Tag="69" IconVisible="False" LeftMargin="0.0001" RightMargin="-231.0001" TopMargin="-17.5000" BottomMargin="-17.5000" LabelText="最大ライフアップ" ctype="TextBMFontObjectData">
                    <Size X="231.0000" Y="35.0000" />
                    <AnchorPoint ScaleY="0.5000" />
                    <Position X="0.0001" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                    <LabelBMFontFile_CNB Type="Normal" Path="font/zoo_font5.fnt" Plist="" />
                  </AbstractNodeData>
                </Children>
                <AnchorPoint />
                <Position X="219.2194" Y="128.8824" />
                <Scale ScaleX="0.8000" ScaleY="0.8000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.2192" Y="0.2144" />
                <PreSize X="0.0000" Y="0.0000" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="568.0000" Y="330.9999" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.5172" />
            <PreSize X="0.8803" Y="0.9391" />
            <FileData Type="Normal" Path="ui/menu5.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameProjectFile>